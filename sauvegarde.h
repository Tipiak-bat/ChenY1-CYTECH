//
// Created by wopaz on 10/05/2025.
//

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
    HAMSTERE = 1,
    AUTRUCHE = 2,
    CHAT = 3,
    CHIEN = 4
} Espece;

#endif //SAUVEGARDE_H
