#include <stdio.h>
#include "main.h"

char* scan_nom(const char *message, int choix); // Prototype de la fonction pour scanner les noms
void printtab(Animal *animaux, int taille);

int main() {
    Animal animaux[TAILLE]; // Tableau pour stocker les animaux
    int choix;

    // Initialisation des cages vides
    for (int i = 0; i < TAILLE; i++) { // La cage 0 est intialisée mais jamais utilisée
        animaux[i].keyid = -i; // Indique une cage vide
        animaux[i].nom[0]='\0';
        animaux[i].espece=0;
        animaux[i].b_year=0;
        animaux[i].weight=0;
        animaux[i].phrase[0] ='\0';
    }

    do {
        affiche_menu(); // Affiche le menu principal
        printf("Quel est votre choix ?\n");
        scanf("%d", &choix);

        if( choix < 1 || choix > 9) {
            printf("[ERREUR] Choix invalide. Veuillez entrer un numéro entre 1 et 10.\n"); // Recommence la boucle si le choix est invalide
        } else {
            switch (choix) {
                case 1:
                    Menu_Rechercher_animal(animaux, TAILLE); // Fonction de recherche
                break;
                case 2:
                    if (Menu_Ajouter_Animal(animaux, TAILLE) == 0) {
                        printf("Animal ajouté avec succès.\n");
                    } else {
                        printf("Erreur lors de l'ajout de l'animal.\n");
                    }
                break;
                case 3:
                    Menu_Supprimer_animal(animaux, TAILLE);
                break;
                case 4:
                    Inventaire_par_espece(animaux, TAILLE);
                break;
                case 5:
                    Nettoyage_hebdomadaire(animaux, TAILLE);
                break;
                case 6:
                    menu_sauv_rest(animaux, TAILLE); // Menu de sauvegarde et restauration
                break;
                case 7:
                    Imprimer_animaux(animaux, TAILLE);
                break;
                case 8:
                    if (Quitter_le_Menu(animaux, TAILLE)) {
                        return 0; // Quitte le programme
                    }
                break;
                case 9:
                    printf("Crédits : Projet réalisé par l'équipe MI6-N 2025.\n");
                break;
                case 10:
                    printtab(animaux, TAILLE);
                break;
                default:
                    printf("Erreur : veuillez saisir un numéro entre 1 et 9.\n");
            }
        }
    } while (1);//choix >= 1 && choix <= 9);

    return 0;
}

void printtab(Animal *animaux, int taille) {
    printf("=== Liste tableau ===\n");
    for (int i = 0; i < taille; i++) {
            printf("i : %d,\n ID: %d,\n Nom: %s,\n Espèce: %d,\n Année de naissance: %d,\n Poids: %.2f kg\n\n",
                   i, animaux[i].keyid, animaux[i].nom, animaux[i].espece,
                   animaux[i].b_year, animaux[i].weight);
        }
    }


char* scan_nom(const char *message, int choix) {
    static char nom[MAX_NOM + 1]; // Tableau statique pour stocker le nom
    char buffer[MAX_NOM + 2];    // +2 pour gérer le '\n' et le '\0'
    int valide;

    do {
        valide = 1;
        printf("%s\n", message); // Afficher le message personnalisé

        // Lecture de l'entrée utilisateur
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("[ERREUR] Saisie invalide. Veuillez réessayer.\n");
            valide = 0;
            continue;
        }

        // Vérification si l'entrée est trop longue
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0'; // Retirer le '\n'
        } else {
            printf("[ERREUR] Nom trop long. Veuillez réessayer.\n");
            // Vider le buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            valide = 0;
            continue;
        }

        // Vérification si l'utilisateur n'a rien saisi
        if(choix == 1){
            if (strlen(buffer) == 0) {
                printf("[ERREUR] Le nom ne peut pas être vide. Veuillez réessayer.\n");
                valide = 0;
                continue;
            }
        }
        // Vérification des espaces
        for (size_t i = 0; i < len; i++) {
            if (buffer[i] == ' ') {
                printf("[ERREUR] Le nom ne doit pas contenir d'espaces. Veuillez réessayer.\n");
                valide = 0;
                break;
            }
        }

    } while (!valide);

    // Copier le nom validé dans le tableau statique
    strncpy(nom, buffer, MAX_NOM);
    nom[MAX_NOM] = '\0'; // S'assurer que la chaîne est terminée


    return nom;
}
