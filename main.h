#ifndef MAIN_H

#define MAIN_H

   #include <stdio.h>
   #include <string.h>
   #include <stdlib.h>
   #include <time.h>
   #define SIZE 50

typedef struct Animal {
    int keyid;
    char nom[25];
    int espece;
    int b_year;
    float weight;
    char phrase[255];
} Animal;



typedef enum Espece{
    HAMSTERE = 1,
    AUTRUCHE = 2,
    CHAT = 3,
    CHIEN = 4
} Espece;

void affiche_menu();
int Rechercher_animal();
int addAnimal(Animal animaux[], int size);
int Supprimer_animal(Animal animaux[], int nb_animaux);
int Inventaire_par_espece(Animal animaux[], int nb_animaux);
int Nettoyage_hebdomadaire(Animal animaux[], int nb_animaux);
int Quitter_le_Menu();

#endif //MAIN_H
