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
                printf("Erreur d'allocation mémoire.\n");
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

/*int ajout_animal(Animal* tab, char* nom, int espece, int b_year, int weight, char* phrase) {
    int a = 0;

    for (int i = 1; i < SIZE; i++) {
        if (tab[i].keyid > 0) {
            a++;
        }
    }

    if (a < 50) {
        if (b_year < 0 || b_year > YEAR || espece < -1 || espece > 4) {
            return 1; // Erreur dans les données fournies
        }

        for (int i = 1; i < SIZE; i++) {
            if (tab[i].keyid < 0) {
                tab[i].keyid = i;
                strncpy(tab[i].nom, nom, sizeof(tab[i].nom) - 1);
                tab[i].nom[sizeof(tab[i].nom) - 1] = '\0';
                tab[i].espece = espece;
                tab[i].b_year = b_year;
                tab[i].weight = weight;
                strncpy(tab[i].phrase, phrase, sizeof(tab[i].phrase) - 1);
                tab[i].phrase[sizeof(tab[i].phrase) - 1] = '\0';
                break;
            }
        }
    } else {
        return 1; // Impossible d'ajouter un animal (tableau plein)
    }

    return 0; // Succès
}

int delete_an_animal(Animal* tab, int id){
    int test=1;
    if(id<1||id>SIZE){
        printf("Erreur dans le choix de l'identifiant.\n");
        exit(3);
    }
    else{
        for(int i=1; i<SIZE; i++){
            if(id==tab[i].keyid){
                printf("Animal %d\n",tab[i].keyid);
                tab[i].keyid=i*(-1);
                tab[i].nom[0]='\0';
                tab[i].espece=0;
                tab[i].b_year=0;
                tab[i].weight=0;
                tab[i].phrase[0] ='\0';
                i=SIZE;
                test=0;
            }
        }
        if(test){
            printf("Animal non trouvé.\n");
        }
        else{
            printf("Animal supprimé avec succès.\n");
        }

    }
    return 0;
}*/
