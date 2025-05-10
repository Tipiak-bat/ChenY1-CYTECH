#include<stdio.h>
#include <stdlib.h>
#include <string.h>



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
    int espece;
} Animal;

// pour la fonction supprimer animal 
typedef struct {
    int id;
    char nom[50];
} Animal; 

void affiche_Menu();
