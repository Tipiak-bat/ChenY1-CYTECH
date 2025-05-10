#ifndef MAIN_H

#define MAIN_H

   #include <stdio.h>
   #include <string.h>
   #include <stdlib.h>
   #include <time.h>
   #define SIZE 50

typedef struct
 {
    int keyid;
    char nom[25];
    int espece;
    int b_year;
    int weight;
    char phrase[255];
 } Animal;

//c'est pour aryem quand j'ai fait la fonction ajouter animal je savais pas ou mettre desoler 
 typedef struct {
    int identifiant;
    char nom[50];
    int espece;
    int annee_naissance;
    float poids;
    char categorie_age[10];
} Animal;

// pour la fonction nettoyage hebdomadaire 
typedef struct {
    int id;
    char nom[50];
    int species;
} Animal;


typedef enum
{
    INDEFINI = 0,
    HAMSTERE = 1,
    AUTRUCHE = 2,
    CHAT = 3,
    CHIEN = 4
} Espece;

 Animal animals[SIZE];

#endif //MAIN_H
