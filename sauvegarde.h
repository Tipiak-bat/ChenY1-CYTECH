#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H

#include <stdio.h>

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

#endif //SAUVEGARDE_H
