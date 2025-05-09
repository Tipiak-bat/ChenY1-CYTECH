#include "menu.h"

int Rechercher_animal(){
    char r_name[25] = "";
    int r_espece = -1;
    int categorie_age = 0;

    printf("\n=====Recherche=====\n");
    printf("Laissez votre saisie vide si vous souhaitez ne pas rechercher en fonction de ce critère\n");
    printf("Saisir le nom de l'animal :\n");
    // !!! il faut savoir l'expliquer,
    if (fgets(r_name, sizeof(r_name), stdin) != NULL) {
        // Supprimer le saut de ligne si présent
        size_t len = strlen(r_name);
        if (len > 0 && r_name[len - 1] == '\n') {
            r_name[len - 1] = '\0';
        }
    }
    if (strlen(r_name) == 0) {
        strcpy(r_name, "");
    }

    printf("Liste des IDs :\nIGNORER L'ESPECE = -1\n INDEFINI = 0\n HAMSTERE = 1\n AUTRUCHE = 2\n CHAT = 3\n CHIEN = 4\n");
    printf("Saisir l'ID de l'espèce :\n");
    scanf("%d", &r_espece);
    if (r_espece > 4 || r_espece < -1) {
        printf("[ERROR] Saisie invalide, retour au menu");
        return 1;
    }

    printf("Rechercher un animal (0 - IGNORER, 1 - Jeune, 2 - Adulte, 3 - Senior) : \n");
    scanf("%d", &categorie_age);
    if (categorie_age < 0 || categorie_age > 3) {
        printf("[ERROR] Saisie invalide, retour au menu\n");
        return 1;
    }

    // recherche en cours
    // Amina les valeurs par défaut sont "" pour le nom, -1 pour l'espèce, 0 pour la catégorie d'age
    // recherche_animaltab(r_name, r_espece, categorie_age);
    return 0;
  }

int Ajouter_animal(){
   char nom[30];
    int espece = -1;
    int age = -2;
    int retour;

    printf("===== AJOUTER UN ANIMAL =====\n");

    // saisir le nom de l'animal
    printf("Entrez le nom de l'animal  : ");
    scanf("%s", nom);  // Pas de vérification ici car scanf bloque déjà si c’est pas du texte

    // Saisie de l'espèce AVEC vérification
    do { 
        printf("\nEspèces disponibles :\n");
        printf("0 - Hamster\n");
        printf("1 - Autruche\n");
        printf("2 - Chat\n");
        printf("3 - Chien\n");
        printf("Entrez le numéro de l'espèce (0 à 3) : ");
        retour = scanf("%d", &espece);

        // getchar pour lire une seule lettre a la fois 
        while (getchar() != '\n'); // enlève donc ce que l'utilisateur a mis inutilement 

        if (retour != 1 || espece < 0 || espece > 3) {
            printf("[ERREUR] Entrée invalide. Veuillez recommencer.\n");
            espece = -1; // On force à recommencer
        }
    } while (espece == -1);

    // Saisie de l'âge AVEC vérification
    do {
        printf("Entrez l'âge de l'animal (entre 0 et 30) : ");
        retour = scanf("%d", &age);

        // je vide la memoire ou les lettre inutile vont 
        while (getchar() != '\n');

        if (retour != 1 || age < 0 || age > 30) {
            printf("[ERREUR] Âge invalide. Veuillez recommencer.\n");
            age = -1;
        }
    } while (age == -2);

    // Affichage final
    printf("\nAnimal ajouté avec succès !\n");
    printf("Nom : %s\n", nom);
    printf("Espèce : ");
    switch (espece) {
        case 0: printf("Hamster\n"); break;
        case 1: printf("Autruche\n"); break;
        case 2: printf("Chat\n"); break;
        case 3: printf("Chien\n"); break;
    }
    printf("Âge : %d ans\n", age);

    return 0;
}

int Supprimer_animal(){

  return 0;
}
int Inventaire_par_espece(){

  return 0;
}
int Nettoyage_hebdomadaire(){

  return 0;
}

int Quitter_le_Menu(){
  
  return 0;

}


do {                           // faire boucle do....while pour que le menu s'affiche plusieurs fois
void affiche_menu () {
  printf （"\n====Bienvenue dans Le menu de ChenY1 le Refuge====\n"）；
  printf("1: Vous Recherchez un animal\n");
  printf("2: Vous voulez ajouter un animal\n");
  printf("3: Vous voulez supprimer un animal\n");
  printf("4: Inventaire par espèce\n"); // ler variante inventaire nombre decroissant
  printf("5: Faire le nettoyage hebdomaire\n"); //2eme variante DAY CLEAN
  printf("6: Quitter le menu\n");
  printf("7: Crédit\n");
}

// dans le int main 

int choix; 

affiche_menu();
printf("Quel est votre choix\n");     // on regarde ce qu'a choisie l'utilisateur
scanf ("%d", &choix);
                                     // utiliser switch case car il y a plusieurs valeur
switch (choix) {
        case 1 : 
               Rechercher_animal();
               break;
        case 2 : 
               Ajouter_animal();
               break ;
        case 3 :
               Supprimer_animal();
               break;
        case 4 : 
               Inventaire_par_espece();
               break;
        case 5 :
               Nettoyage_hebdomadaire();
               break; 
        case 6 : 
               Quitter_le_Menu();
               break;
default:
        printf("Erreur: veuiller saisir un numéro entre 1 et 6");
while(choix > 0 || choix > 6);                       // ne pas quitter tant que l'utilisateur n'a pas choisie un numéro entre 1 et 6
}
return 0; 
}
