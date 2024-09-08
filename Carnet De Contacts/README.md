# Gestion de Contacts en C

Ce programme est un gestionnaire de contacts simple, écrit en C, qui permet aux utilisateurs de gérer une liste de contacts avec des fonctionnalités de base telles que l'ajout, l'affichage, la modification et la suppression de contacts. Les contacts sont stockés dans un fichier et chargés automatiquement au démarrage du programme.

## Fonctionnalités

- **Ajouter un contact** : Les utilisateurs peuvent ajouter un nouveau contact en entrant un nom, un numéro de téléphone et un email.
- **Afficher tous les contacts** : Affiche tous les contacts enregistrés dans l'ordre alphabétique.
- **Modifier un contact** : Permet de modifier le nom, le numéro de téléphone et l'email d'un contact existant.
- **Supprimer un contact** : Les utilisateurs peuvent supprimer un contact en fournissant le nom.
- **Rechercher un contact** : Permet de rechercher un contact par nom et d'afficher ses détails.
- **Sauvegarde et chargement des contacts** : Les contacts sont sauvegardés dans un fichier (`contacts.txt`) et chargés automatiquement au démarrage du programme.
- **Insertion ordonnée** : Les contacts sont insérés dans l'ordre alphabétique en fonction de leur nom.

## Comment ça fonctionne

1. Le programme commence par charger tous les contacts depuis le fichier `contacts.txt` s'il existe.
2. Il affiche ensuite un menu avec les options suivantes :
   - Ajouter un nouveau contact
   - Afficher tous les contacts
   - Modifier un contact existant
   - Supprimer un contact
   - Rechercher un contact
   - Quitter le programme
3. Lors de la sortie du programme, tous les contacts sont sauvegardés dans le fichier `contacts.txt`.

## Structure du fichier

- **contacts.txt** : Stocke tous les contacts dans un format texte simple.
- **Structure du contact** : Chaque contact est représenté par les champs suivants :
  - Nom (Max 31 caractères)
  - Numéro de téléphone (Max 11 caractères)
  - Email (Max 31 caractères)

## Compilation

Pour compiler le programme, utilisez la commande suivante :

```bash
gcc carnet_de_contacts.c -o carnet_de_contacts
