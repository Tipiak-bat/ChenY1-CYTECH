#ifndef MAIN_H

#define MAIN_H

   #include <stdio.h>
   #include <string.h>
   #include <stdlib.h>
   #include <time.h>
   #define SIZE 51

typedef struct Animal {
    int keyid;
    char nom[25];
    int espece;
    int b_year;
    float weight;
    char phrase[255];
} Animal;



typedef enum
{
    CHIEN = 1,
    CHAT = 2,
    AUTRUCHE = 3,
    HAMSTERE = 4
} Espece;

void affiche_menu();
int Rechercher_animal();
int addAnimal(Animal * animaux, int size);
int Supprimer_animal(Animal * animaux, int nb_animaux);
int Inventaire_par_espece(Animal * animaux, int nb_animaux);
int Nettoyage_hebdomadaire(Animal *animaux, int nb_animaux);
int menu_sauv_rest(Animal * animaux, int nb_animaux);
int Quitter_le_Menu();
int Imprimer_animaux(Animal *animaux, int taille);


#endif //MAIN_H
