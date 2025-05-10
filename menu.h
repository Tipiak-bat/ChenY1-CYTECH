
#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
    HAMSTERE = 1,
    AUTRUCHE = 2,
    CHAT = 3,
    CHIEN = 4
} Espece;

// Function declarations
int Rechercher_animal();
Animal ajouter_Animal();
int Supprimer_animal(Animal animaux[], int nb_animaux);
int Inventaire_par_espece(Animal animaux[], int nb_animaux);
int Nettoyage_hebdomadaire(Animal animaux[], int nb_animaux);
int Quitter_le_Menu();
void affiche_Menu();

#endif
