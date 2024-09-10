# Gestion des Tâches en C

Ce programme est un gestionnaire de tâches simple, écrit en C, qui permet aux utilisateurs de gérer une liste de tâches avec des fonctionnalités de base telles que l'ajout, l'affichage, la modification et la suppression de tâches. Les tâches sont stockées dans un fichier et chargées automatiquement au démarrage du programme.

## Fonctionnalités

- **Ajouter une tâche** : Les utilisateurs peuvent ajouter une nouvelle tâche en entrant un titre, une description et une date limite.
- **Afficher toutes les tâches** : Affiche toutes les tâches enregistrées, triées par titre ou par date limite.
- **Modifier une tâche** : Permet de modifier le titre, la description ou la date limite d'une tâche existante.
- **Supprimer une tâche** : Les utilisateurs peuvent supprimer une tâche en fournissant son ID.
- **Rechercher une tâche** : Permet de rechercher une tâche par titre ou par ID et d'afficher ses détails.
- **Afficher les tâches urgentes** : Montre les tâches dont la date limite est proche (moins de 3 jours).
- **Sauvegarde et chargement des tâches** : Les tâches sont sauvegardées dans un fichier (`taches.txt`) et chargées automatiquement au démarrage du programme.
- **Statistiques** : Permet d'afficher des statistiques sur les tâches en fonction de leur statut (complètes ou non).

## Comment ça fonctionne

1. Le programme commence par charger toutes les tâches depuis le fichier `taches.txt` s'il existe.
2. Il affiche ensuite un menu avec les options suivantes :
   - Ajouter une nouvelle tâche
   - Afficher toutes les tâches
   - Modifier une tâche existante
   - Supprimer une tâche
   - Rechercher une tâche
   - Afficher les tâches urgentes
   - Afficher les statistiques
   - Quitter le programme
3. Lors de la sortie du programme, toutes les tâches sont sauvegardées dans le fichier `taches.txt`.

## Structure du fichier

- **taches.txt** : Stocke toutes les tâches dans un format texte simple.
- **Structure de la tâche** : Chaque tâche est représentée par les champs suivants :
  - ID (Identifiant unique)
  - Titre (Max 31 caractères)
  - Description (Max 100 caractères)
  - Statut (Complète ou non)
  - Deadline (Date limite avec jour, mois, année)

## Compilation

Pour compiler le programme, utilisez la commande suivante :

```bash
gcc gestion_des_tàches.c -o gestion_des_tàches
