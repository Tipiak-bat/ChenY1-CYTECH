#ifndef FONCTIONNALITE_H
#define FONCTIONNALITE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 51
#define YEAR 2025

typedef struct
{
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

int* Rechercher_animal(Animal* tab, int nb_elements,char* nom, int espece, int type);
/*int ajout_animal(Animal* tab, char* nom, int espece, int b_year, int weight, char* phrase);
int delete_an_animal(Animal* tab, int id);*/

#endif
