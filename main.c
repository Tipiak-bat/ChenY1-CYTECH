#include <stdio.h>
#include "main.h"

int main() {
    Animal animaux[50]; // Tableau pour stocker les animaux
    int nb_animaux = 0;  // Nombre d'animaux dans le tableau
    int choix;

    // Initialisation des cages vides
    for (int i = 0; i < 50; i++) {
        animaux[i].keyid = -i; // Indique une cage vide
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
                if (addAnimal(animaux, 50) == 0) {
                    nb_animaux++;
                    printf("Animal ajouté avec succès.\n");
                } else {
                    printf("Erreur lors de l'ajout de l'animal.\n");
                }
            break;
            case 3:
                nb_animaux = Supprimer_animal(animaux, nb_animaux);
            printf("Animal supprimé avec succès.\n");
            break;
            case 4:
                Inventaire_par_espece(animaux, nb_animaux);
            break;
            case 5:
                Nettoyage_hebdomadaire(animaux, nb_animaux);
            break;
            case 6:
                if (Quitter_le_Menu()) {
                    return 0; // Quitte le programme
                }
            break;
            case 7:
                printf("Crédits : Projet réalisé par l'équipe CYTech 2025.\n");
            break;
            default:
                printf("Erreur : veuillez saisir un numéro entre 1 et 7.\n");
        }
    } while (choix >= 1 && choix <= 7);

    return 0;
}
