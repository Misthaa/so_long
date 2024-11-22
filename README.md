# so_long - Samourai Dash

## 🚀 Description  
**so_long** est un projet de l'École 42 qui consiste à créer un petit jeu en 2D où un personnage doit collecter des objets et atteindre une sortie, tout en respectant certaines contraintes techniques (comme le parsing de cartes et la gestion d'événements).  
Le projet met en avant des compétences en programmation C, gestion d'événements graphiques et manipulation de bibliothèques graphiques comme la **c**.
Je n'ai pas fait de règle bonus pour le projet car j'avais commencé a faire des parties du bonus avant la finalisation du mandatory.

![Screencast-from-11-22-2024-06_25_00-PM](https://github.com/user-attachments/assets/2e216393-5eed-4585-ba7f-521b9ced86af)

---

## 🛠️ Fonctionnalités  
-  **Gestion de carte** : Support des fichiers `.ber` pour définir les niveaux.
-  **Mécaniques de jeu** : Collecte d'objets, gestion des déplacements et détection de victoire.
-  **Affichage graphique** : Utilisation de la bibliothèque **MacroLibX** pour le rendu en 2D.
-  **Gestion des erreurs** : Vérification des fichiers de carte (validité, dimensions, murs, etc.).
-  **Système optimisé** : Prise en charge des événements clavier pour des mouvements fluides.

---

## 📦 Installation  

1. **Cloner le dépôt :**
   ```bash
   git clone https://github.com/ton-utilisateur/so_long.git
   cd so_long
   ```

2. **Compiler le projet :**
   ```bash
   cd MacroLibX
   make
   cd ..
   make
   ```

3. **Lancer le jeu :**
   ```bash
   ./so_long [map/valid_map/level3.ber]
   ```

![image](https://github.com/user-attachments/assets/a5165140-74db-4169-94db-76ffc46f9bfa)

---

## 📋 Règles des cartes  
- Le fichier `.ber` doit respecter les critères suivants :
  - **Encadré de murs** : La carte doit être entourée de `1`.
  - **Un joueur** : Exactement un `P`.
  - **Une sortie** : Exactement un `E`.
  - **Au moins un objet** : Au moins un `C`.
  - **Format rectangulaire** : Toutes les lignes doivent avoir la même longueur.

Exemple de fichier `.ber` :
```
111111
1P0C01
100001
1C0E01
111111
```

---

## 🎮 Contrôles du jeu  
- **Z / Q / S / D** : Déplacer le personnage.
- **Échap** : Quitter le jeu.

---

## 🖥️ Dépendances  
Pour compiler et exécuter le projet, vous aurez besoin de :
- **MacroLibX** (inclus dans le projet).
- Un environnement compatible avec **X11** (Linux).

---

## 🧑‍💻 Auteur  
- **[Mathis]** (madegryc)
