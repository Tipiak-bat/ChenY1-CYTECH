#include "main.h"

int printTab(int size, Animal * animals){
    if(size < 0 || animals == NULL) {
        printf("[ERROR] Paramètres invalides : animals est NULL ou size < 0\n");
    }
    for(int i = 0; i < size; i++) {
        if(animals[i].keyid < 0) {
            continue;
        }
        printf("%d %s %d %d %d %s\n\n",
                      animals[i].keyid,
                      animals[i].nom,
                      animals[i].espece,
                      animals[i].b_year,
                      animals[i].weight,
                      animals[i].phrase);
    }
    return 0;
}

// Fonction pour ajouter un animal VIA une demande utilisateur (scanf, printf, etc)...
int emptyCages(Animal * animals, int size) {
    int nmb = 0;
    for(int i = 0; i < size; i++){
        if(animals[i].keyid < 0 ) {
            nmb++;
        }
    }
}
int addAnimal(Animal *animals, int size) {
    if (animals == NULL || size <= 0) {
        printf("[ERROR] Paramètres invalides : animals est NULL ou size <= 0\n");
        return 1;
    }

    int f_empty = 0;
    while(f_empty < size && animals[f_empty].keyid >= 0) {
        f_empty++;
    }

    printf("Entrez les informations de l'animal (keyid, nom, espece, b_year, weight, phrase) :\n");
    scanf("%d %s %d %d %d %s\n",
                      animals[f_empty].keyid,
                      animals[f_empty].nom,
                      animals[f_empty].espece,
                      animals[f_empty].b_year,
                      animals[f_empty].weight,
                      animals[f_empty].phrase);

    return 0;
}
