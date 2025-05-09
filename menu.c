#include "menu.h"


void affiche_menu () {
  printf （"\n====Bienvenue dans Le menu de ChenY1 le Refuge====\n"）；
  printf("1: Vous Recherchez un animal\n");
  printf("2: Vous voulez ajouter un animal\n");
  printf("3: Vous voulez supprimer un animal\n");
  printf("4: Inventaire par espèce\n"); // ler variante inventaire nombre decroissant
  printf("5: Faire le nettoyage hebdomaire\n"); //2eme variante DAY CLEAN
  printf("6: Quitter le menu\n");
}

// dans le int main 

int choix; 

            // faire boucle do....while pour que le menu s'affiche plusieurs fois
do {
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
while(choix != 6);                       // ne pas quitter tant que l'utilisateur na pas choisie le numéro 6

return 0; 
}
