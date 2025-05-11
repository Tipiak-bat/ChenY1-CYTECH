
#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 51


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


int Menu_Rechercher_animal(Animal * animaux, int taille);
int Menu_Ajouter_Animal(Animal *animaux, int taille);
int Menu_Supprimer_animal(Animal * animaux, int nb_animaux);
int Inventaire_par_espece(Animal * animaux, int nb_animaux);
int Nettoyage_hebdomadaire(Animal * animaux, int nb_animaux);
int Imprimer_animaux(Animal *animaux, int taille);
int Quitter_le_Menu(Animal * animaux, int nb_animaux);
void affiche_Menu();
int restauration(Animal *animals, int taille);
int sauvegarde(Animal *animals, int taille);
int menu_sauv_rest(Animal *animaux, int nb_animaux);
char* scan_nom(const char *message);
int* Rechercher_animal(Animal* tab, int nb_elements,char* nom, int espece, int type);

#endif
