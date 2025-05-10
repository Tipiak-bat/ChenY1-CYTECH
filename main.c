#include <stdio.h>
#include "main.h"

int main() {
    Animal animaux[SIZE]; // Tableau pour stocker les animaux
    int nb_animaux = 0;  // Nombre d'animaux dans le tableau
    int choix;

    // Initialisation des cages vides
    for (int i = 1; i < SIZE; i++) {
        animaux[i].keyid = -i; // Indique une cage vide
        strcpy(animaux[i].phrase, "");
    }

    do {
        affiche_menu(); // Affiche le menu principal
        printf("Quel est votre choix ?\n");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                Rechercher_animal(); // Fonction de recherche
            break;
            case 2:
                if (Ajouter_Animal(animaux, SIZE) == 0) {
                    nb_animaux++;
                    printf("Animal ajouté avec succès.\n");
                } else {
                    printf("Erreur lors de l'ajout de l'animal.\n");
                }
            break;
            case 3:
                nb_animaux = Supprimer_animal(animaux, SIZE);
            printf("Animal supprimé avec succès.\n");
            break;
            case 4:
                Inventaire_par_espece(animaux, SIZE);
            break;
            case 5:
                Nettoyage_hebdomadaire(animaux, SIZE);
            break;
            case 6:
                menu_sauv_rest(animaux, SIZE); // Menu de sauvegarde et restauration
            break;
            case 7:
                Imprimer_animaux(animaux, SIZE);
            break;
            case 8:
                if (Quitter_le_Menu(animaux, SIZE)) {
                    return 0; // Quitte le programme
                }
            break;
            case 9:
                printf("Crédits : Projet réalisé par l'équipe CYTech 2025.\n");
            break;
            default:
                printf("Erreur : veuillez saisir un numéro entre 1 et 8.\n");
        }
    } while (choix >= 1 && choix <= 9);

    return 0;
}
