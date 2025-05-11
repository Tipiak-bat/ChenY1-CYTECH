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
 int weight;
 char phrase[255];
} Animal;


typedef enum
{
IGNORER = -1,
INDEFINI = 0,
HAMSTERE = 1,
AUTRUCHE = 2,
CHAT = 3,
CHIEN = 4
} Espece;

#endif
