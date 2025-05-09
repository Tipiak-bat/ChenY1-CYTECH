#include "menu.h"

int Rechercher_animal(){
    char r_name[25]; // En dynamique pour dimanche si possible
    int r_espece = -1;
    int categorie_age;

    printf("\n=====Recherche=====\n");
    printf("Laissez votre saisie vide si vous souhaitez ne pas rechercher en fonction de ce critères\n");
    printf("Saisir le nom de l'animal :\n");
    scanf("%s", r_name);
    printf("Liste des IDs :\n INDEFINI = 0\n HAMSTERE = 1\nAUTRUCHE = 2\nCHAT = 3\nCHIEN = 4\n");
    printf("Saisir l'ID de l'espèce :\n");
    scanf("%d", &r_espece);
    if(r_espece>4 || r_espece < -1) {
        printf("[ERROR] Saisie invalide, retour au menu");
        return 1;
    }
    printf("Rechercher un animal (1 - Jeune, 2 - Adulte, 3 - Senior) : \n");
    scanf("%d", &categorie_age);
    if (categorie_age < 0 || categorie_age > 3) {
        printf("[ERROR] Saisie invalide, retour au menu\n");
        return 1;
    }
    // recherche en cours
    // recherche_animal(r_name, r_espece, categorie_age);
    return 0;
  }

int Ajouter_animal(){
  printf (format"
  
  printf ("nom de l'animal que vous voulez ajouter");

  printf("Quel est l'espèce de l'animal : Chien , chat, Hamster, autruche ");

  printf("l'année de naissance de l'animal");

  printf("le poids de l'animal");

  
  
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
