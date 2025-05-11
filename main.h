#ifndef MAIN_H

#define MAIN_H

   #include <stdio.h>
   #include <string.h>
   #include <stdlib.h>
   #include <time.h>
   #define TAILLE 51
   #define MAX_NOM 25
   #define MAX_PHRASE 255

typedef struct Animal {
    int keyid;
    char nom[MAX_NOM];
    int espece;
    int b_year;
    float weight;
    char phrase[MAX_PHRASE];
} Animal;


typedef enum
{
    CHIEN = 1,
    CHAT = 2,
    AUTRUCHE = 3,
    HAMSTERE = 4
} Espece;

void affiche_menu();
int Menu_Rechercher_animal(Animal * animaux, int taille);
int Menu_Ajouter_Animal(Animal * animaux, int taille);
int Menu_Supprimer_animal(Animal * animaux, int nb_animaux);
int Inventaire_par_espece(Animal * animaux, int nb_animaux);
int Nettoyage_hebdomadaire(Animal *animaux, int nb_animaux);
int menu_sauv_rest(Animal * animaux, int nb_animaux);
int Quitter_le_Menu(Animal * animaux, int nb_animaux);
int Imprimer_animaux(Animal *animaux, int taille);
char * scan_nom(const char *message);

#endif //MAIN_H
