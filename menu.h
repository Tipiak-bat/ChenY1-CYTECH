
#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50


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


int Rechercher_animal();
Animal ajouter_Animal();
int Supprimer_animal(Animal * animaux, int nb_animaux);
int Inventaire_par_espece(Animal * animaux, int nb_animaux);
int Nettoyage_hebdomadaire(Animal * animaux, int nb_animaux);
int Quitter_le_Menu(Animal * animaux, int nb_animaux);
void affiche_Menu();
int restauration(Animal *animals, int size);
int sauvegarde(Animal *animals, int size);
int menu_sauv_rest(Animal *animaux, int nb_animaux);

#endif
