# Cahier des charges — Projet Kepler

**Date de rendu :** 16 Juin 2026  
**Groupe :** Jules Chevrier - Jean-Côme Chopin
**Encadrant :** Florian Bescher (@flobsh)

---

### .Mini-jeu : Atterrissage sur Terre (Raylib)

**Description :** Un mini-jeu en C utilisant la bibliothèque graphique Raylib dans lequel le joueur contrôle une fusée spatiale. Il doit entrer une vitesse initiale (vecteur v0) et tenter de faire atterrir la fusée sur la Terre, en tenant compte de la physique gravitationnelle réelle.

**Technologies utilisées :**
- C (logique de jeu, simulation physique)
- Raylib (rendu graphique 2D)

**Fonctionnalités :**
- Écran d'introduction avec scénario narratif
- Saisie interactive du vecteur vitesse initiale (vx, vy) via le clavier
- Position initiale de la fusée générée aléatoirement dans le système solaire
- Simulation physique de la trajectoire de la fusée et de la Terre
- Affichage animé de la trajectoire (traînée + point mobile)
- Halo lumineux autour du Soleil
- Fond étoilé généré aléatoirement
- Zoom dynamique avec la molette de la souris (Camera2D)
- Écran de fin avec message selon le résultat :
  - Atterrissage réussi
  - Crash solaire
  - Crash terrestre
  - Sortie dans le vide spatial
  - Panne de carburant

---

## . Architecture du code

```
Kepler/
├── src/
│   ├── main.c          # Point d'entrée
│   ├── algo.c/.h       # Structures de données et utilitaires
│   ├── physic_calc.c/.h # Calculs physiques (accélération, vitesse, position, énergie)
│   ├── logic.c/.h      # Logique de simulation et conditions de fin
│   └── render.c/.h     # Rendu graphique Raylib
└── website/
    ├── index.html       # Page web
    ├── graphs.js        # Création des graphes Observable Plot
    ├── style.css        # Feuille de style
    ├── d3.js            # Bibliothèque D3
    └── plot.js          # Bibliothèque Observable Plot
```

Le code est modulaire, documenté au format Doxygen, et respecte les bonnes pratiques suivantes :
- Fonctions courtes et à responsabilité unique
- Gestion des erreurs sur les allocations dynamiques
- Libération systématique de la mémoire allouée (`destroy_Tab_Earth`, `destroy_Tab_Rocket`)

---

## . Gestion de projet

- Versionning avec **Git** en mode **trunk-based development**
- Chaque fonctionnalité développée sur une branche dédiée
- Intégration sur `main` via pull-request validée par les deux membres
- Dépôt hébergé sur GitHub, encadrant invité (@flobsh)

### Partage des tâches

| Tâche | Responsable |
|---|---|
| Simulation physique (C) | Jean-Côme Chopin |
| Rendu graphique Raylib | Jules Chevrier |
| Logique de jeu | Jean-Côme Chopin|

---

## . Technologies utilisées

| Technologie | Usage |
|---|---|
| C (C11) | Simulation physique, logique de jeu |
| Raylib | Rendu graphique 2D du mini-jeu |
| Git / GitHub | Versionning et collaboration |
| Doxygen | Documentation du code |

