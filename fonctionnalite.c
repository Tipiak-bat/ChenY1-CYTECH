#include"fonctionnalite.h"

int* Rechercher_animal(Animal* tab, int nb_elements, char* nom, int espece, int type) {
    int* options = NULL;
    int j = 0; // Compteur pour les résultats

    printf("\n===== Résultats de la recherche =====\n");

    for (int i = 1; i < nb_elements; i++) {
        if (tab[i].keyid < 0) continue; // Cage vide
        int age = YEAR - tab[i].b_year;

        // Vérification des critères
        if (strlen(nom) > 0 && strcmp(tab[i].nom, nom) != 0) continue;
        if (espece != -1 && tab[i].espece != espece) continue;
        if (type != -1 && ((type == 0 && age >= 2) || (type == 1 && age <= 10))) continue;

        // Si un animal correspond, on l'ajoute aux résultats
        if (options == NULL) {
            options = malloc(SIZE * sizeof(int));
            if (options == NULL) {
                printf("[ERREUR] Erreur d'allocation mémoire.\n");
                exit(1);
            }
        }

        options[j++] = i;

        // Affichage des informations de l'animal
        printf("\nAnimal trouvé :\n");
        printf("  ID : %d\n", tab[i].keyid);
        printf("  Nom : %s\n", tab[i].nom);
        printf("  Espèce : ");
        switch (tab[i].espece) {
            case CHIEN: printf("Chien\n"); break;
            case CHAT: printf("Chat\n"); break;
            case AUTRUCHE: printf("Autruche\n"); break;
            case HAMSTERE: printf("Hamster\n"); break;
            default: printf("Inconnue\n");
        }
        printf("  Année de naissance : %d\n", tab[i].b_year);
        printf("  Poids : %.2f kg\n", tab[i].weight);
        printf("  Description : %s\n", tab[i].phrase);
        printf("-----------------------------");
    }

    if (j == 0) {
        printf("\nAucun animal ne correspond aux critères.\n");
    }

    return options;
}
