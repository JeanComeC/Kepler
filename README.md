# KEPLER

## Concept
**Kepler** est un projet implémentant un générateur de labyrinthes en C, basé sur l'algorithme Randomized Depth-First Search (RDFS). Le labyrinthe est représenté sous forme de grille de cellules reliées entre elles. Une fois généré, le labyrinthe peut être résolu par trois algorithmes au choix : BFS, Dijkstra, ou A*. Le programme s'exécute en ligne de commande en précisant les dimensions souhaitées.

## Structure des Fichiers
Le projet est organisé comme suit :

- **src/** : Répertoire contenant les fichiers source du projet.
  - **main.c** : Point d'entrée du programme, responsable de l'initialisation, de la génération et de la résolution du Labyrinthe.
  - **physic_calc.c** : Contient les fonctions pour initialiser et générer le Labyrinthe,  et pour l'afficher.
  - **algo.c** : Contient toutes les fonctions relatives à l'algorithme Breadth First Search (BFS).
  - **export.c** : Contient toutes les fonctions relatives à l'algorithme Djikstra.
  - **physic_calc.h**, **algo.h**, **export.h** : Headerfiles définissant les structures (`Cell`, `Grid`, `Position`, ...), les macros, les prototypes des fonctions, et incluant les bibliothèques nécessaires.

- **website/** : Répertoire contenant les fichiers source du site web (HTML/CSS/JS/JSON).
  - **index.html** : ...
  - **script.js** : ...

- **meson.build** : Simplifie la compilation du projet.
- **.gitignore** : Liste les fichiers et dossiers à exclure du suivi Git, comme les fichiers compilés (.o, .exe) afin de ne pas les versionner.
- **LICENSE** : MIT License
- **README.md** : Ce fichier, décrivant le projet, sa structure, et les instructions d'exécution.

## Prérequis
- Un compilateur C (ex. : `gcc`).
- Un système compatible POSIX (Linux, macOS, ou Windows avec WSL/MinGW).
- La bibliothèque standard C. (voir Notes pour mises à jour).

## Instructions pour lancer le programme
1. **Cloner le dépôt** :
   ```bash
   git clone https://github.com/JeanComeC/Kepler.git
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
- Si vous n'avez pas installé meson, faites-le avec la commande :
   ```bash
   sudo apt install meson
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
- Si votre agent SSH s'est déconnecté :
   ```bash
   eval $(ssh-agent -s)
   ssh-add -l
   ssh-add ~/.ssh/name_your_key
   ssh -T git@github.com
   ```