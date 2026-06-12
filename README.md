# KEPLER

## Concept
**Kepler** est un projet de simulation physique de la trajectoire de la Terre autour du Soleil. Un programme en C effectue une intégration numérique (méthode d'Euler) des équations du mouvement à partir des positions et vitesses initiales de la Terre, calculant à chaque pas horaire sa position (x, y, z) ainsi que ses énergies cinétique et potentielle sur une année complète. Les résultats sont exportés au format JSON, puis visualisés via une page web interactive (https://jeancomec.github.io/Kepler/index.html) affichant la trajectoire orbitale animée et l'évolution des énergies cinétique, potentielle et totale au fil du temps.

## Structure des Fichiers
Le projet est organisé comme suit :

- **src/** : Répertoire contenant les fichiers source du projet.
  - **main.c** : Point d'entrée du programme, responsable de l'initialisation, du calcul et de l'écriture des data de la trajectoire.
  - **physic_calc.c** : Contient les fonctions pour calculer les positions pour la trajectoire.
  - **algo.c** : Contient toutes les fonctions pour gérer les tableaux dynamiques.
  - **export.c** : Contient toutes les fonctions relatives à l'écriture pour l'export en fichier .json .
  - **physic_calc.h**, **algo.h**, **export.h** : Headerfiles définissant les structures (`Coordinates`, `Data_output`), les macros, les prototypes des fonctions, et incluant les bibliothèques nécessaires.

- **website/** : Répertoire contenant les fichiers source du site web (HTML/CSS/JS/JSON).
  - **d3.js** : Est une bibliothèque de manipulation de données et de SVG.
  - **plot.js** : Est une bibliothèque simplifiant la construction des graphs.
  - **graphs.js** : Contient les commande pour tracer les graphs.
  - **style.css** : Contient le style de la page index.html .
  - **data.json** : Contient les cordonnée et les valeur pour tracer les graphs.

- **index.html** : Contient le contenue principale de la page.
- **meson.build** : Simplifie la compilation du projet.
- **.gitignore** : Liste les fichiers et dossiers à exclure du suivi Git, comme les fichiers compilés (.o, .exe, .json) afin de ne pas les versionner.
- **LICENSE** : MIT License
- **README.md** : Ce fichier, décrivant le projet, sa structure, et les instructions d'exécution.

## Prérequis
- Un compilateur C (ex. : `gcc`).
- Un système compatible POSIX (Linux, macOS, ou Windows avec WSL/MinGW).
- La bibliothèque standard C. (voir Notes pour mises à jour).

## Instructions pour lancer le programme
1. **Cloner le dépôt** :
   ```bash
   git clone git@github.com:JeanComeC/Kepler.git
   cd Kepler
   ```

2. **Initialiser build/** :
   Avec la commande :
   ```bash
   meson setup build
   ```

3. **Compiler le programme** :
   Avec le `meson.build` :
   ```bash
   meson compile -C build
   ```

4. **Lancer le programme** :
   Exécutez le binaire généré :
   ```bash
   ./build/kepler.exe
   ```

5. **Ouvrer le site web** :
   Lancer la page :
   /website/index.html

## Notes
- Assurez-vous que `...` et `...` soient correctement mis au lancement et qu'ils ne dépassent pas les capacités de votre machine. Vous pouvez modifier les macros `...` et `...` prévues à cet effet.
- Arbitrairement, l'entrée du Labyrinthe se situe en bas à gauche, et la sortie en haut à droite.
- Le programme se termine lorsque l'algorithme choisit par l'utilisateur a fini de résoudre le Labyrinthe.
- Si vous n'avez pas fait les mises à jour, faites-les, avant de compiler le programme, avec la commande :
   ```bash
   sudo apt update && sudo apt upgrade && sudo apt autoremove && sudo apt clean
   ```
- Si vous n'avez pas installé meson et ninja, faites-le avec la commande :
   ```bash
   sudo apt install meson ninja-build build-essential
   ```
- Si votre agent SSH s'est déconnecté :
   ```bash
   eval $(ssh-agent -s)
   ssh-add -l
   ssh-add ~/.ssh/name_your_key
   ssh -T git@github.com
   ```
   - Si vous voulez supprimer les fichiers compilés (.o, .exe) de votre machine, faites-le avec la commande :
   ```bash
   meson compile -C build --clean
   ```
- Si vous voulez supprimer tout notre projet de votre machine, faites-le avec la commande :
   ```bash
   cd ..
   rm -rf Kepler
   ```
