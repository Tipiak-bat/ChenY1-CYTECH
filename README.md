# ChenY1 - Gestion d'un Refuge pour Animaux

Bienvenue dans **ChenY1**, un projet de gestion d'un refuge pour animaux. Ce programme permet de gérer les animaux du refuge, d'effectuer des inventaires, de calculer le temps de nettoyage hebdomadaire, et bien plus encore.

## Fonctionnalités

- **Rechercher un animal** : Trouvez un animal spécifique dans le refuge.
- **Ajouter un animal** : Ajoutez un nouvel animal à la base de données.
- **Supprimer un animal** : Retirez un animal du refuge.
- **Inventaire par espèce** : Affichez le nombre d'animaux par espèce (chiens, chats, autruches, hamsters).
- **Nettoyage hebdomadaire** : Calculez le temps total nécessaire pour nettoyer les cages.
- **Sauvegarde et restauration** : Sauvegardez les données des animaux dans un fichier ou restaurez-les.
- **Quitter le programme** : Fermez l'application en toute sécurité.

## Structure du Projet

- **`main.c`** : Point d'entrée du programme, initialise les données et lance le menu principal.
- **`main.h`** : Déclare les structures et fonctions utilisées dans `main.c`.
- **`fonctionnalite.c`** : Implémente les fonctions utilitaires et les fonctionnalités spécifiques liées à la gestion des animaux.
- **`fonctionnalite.h`** : Déclare les structures et fonctions utilisées dans `fonctionnalite.c`.
- **`menu.c`** : Contient les fonctions principales pour gérer le menu et les interactions utilisateur (principalement les saisies).
- **`menu.h`** : Déclare les structures et fonctions utilisées dans `menu.c`.
- **`sauvegarde.c`** : Implémente les fonctions de sauvegarde et de restauration des données.
- **`sauvegarde.h`** : Déclare les structures et fonctions liées à la sauvegarde.

## Compilation et Exécution

### Prérequis
- Un compilateur C (comme `gcc`).
- L'Utilitaire `make`

### Étapes
1. Clonez le dépôt :
   ```bash
   git clone https://github.com/Tipiak-bat/ProjetInfoCYTech2025.git
   cd ChenY1
   ```
2. Compilez le projet :
   ```bash
   make all
   ```
3. Exécutez le programme :
   ```bash
   ./chenY1
   ```

## Utilisation

1. Lancez le programme.
2. Naviguez dans le menu principal pour accéder aux différentes fonctionnalités.
3. Suivez les instructions affichées à l'écran pour interagir avec le programme.

## Format des Données

Les données des animaux sont sauvegardées dans un fichier `animal.txt` au format suivant :
```
<keyid> <nom> <espece> <b_year> <weight> <phrase>
```
Exemple :
```
1 Rex 4 2018 25.5 "Woof Woof"
```

## Contributeurs

- **Développeur principal** : Adam MEFTAH, Amina BRAIKIA et Aryem ZITOUNE

## Licence

Ce projet est sous licence libre. Vous êtes libre de l'utiliser, de le modifier et de le redistribuer.

## Remarques

- Assurez-vous que le fichier `animal.txt` est accessible en lecture/écriture.
- En cas de problème, vérifiez les messages d'erreur affichés dans la console.

Merci d'utiliser **ChenY1** pour la gestion de votre refuge !
(Un projet pour CYTECH)
