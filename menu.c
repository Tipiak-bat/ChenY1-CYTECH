#include "menu.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int Menu_Rechercher_animal(Animal * animaux, int taille) {
    // on met des valeurs par défaut
    char r_name[25] = "";
    int r_espece = -1;
    int r_age_type = -1; // -1 = pas de critère, 0 = jeune (<2 ans), 1 = senior (>10 ans)

    printf("\n===== Recherche =====\n");
    printf("Laissez votre saisie vide si vous souhaitez ne pas rechercher en fonction de ce critère\n");

    // Critère : Nom
    while (getchar() != '\n'); // Nettoyage du buffer
    char *nom_saisi = scan_nom("Saisir le nom de l'animal (laisser vide pour ignorer ce critère) :", 0);
    if (nom_saisi != NULL && strlen(nom_saisi) > 0) {
        strncpy(r_name, nom_saisi, sizeof(r_name) - 1);
        r_name[sizeof(r_name) - 1] = '\0';
    } else {
        r_name[0] = '\0'; // Valeur par défaut (critère ignoré)
    }

    // Critère : Espèce
    printf("Liste des IDs :\nIGNORER L'ESPECE = -1\n CHIEN = 1\n CHAT = 2\n AUTRUCHE = 3\n HAMSTERE = 4\n");
    printf("Saisir l'ID de l'espèce :\n");
    if (scanf("%d", &r_espece) != 1 || r_espece > 4 || r_espece < -1) {
        printf("[ERREUR] Saisie invalide, retour au menu\n");
        while (getchar() != '\n'); // Nettoyage du buffer
        return 1;
    }

    // Critère : Type d'âge
    printf("Rechercher par type d'âge :\n");
    printf("IGNORER = -1, JEUNE (<2 ans) = 0, SENIOR (>10 ans) = 1\n");
    if (scanf("%d", &r_age_type) != 1 || r_age_type < -1 || r_age_type > 1) {
        printf("[ERREUR] Saisie invalide, retour au menu\n");
        while (getchar() != '\n'); // Nettoyage du buffer
        return 1;
    }

    /*if(r_name == "" && r_espece == -1 && r_age_type == -1){
        Imprimer_animaux(animaux, taille);
        return 0;
    } else {*/
        // Appel de la fonction de recherche
        int *resultats = Rechercher_animal(animaux, taille, r_name, r_espece, r_age_type);
        if (resultats == NULL) {
           printf("Aucun animal trouvé.\n");
           return 1;
        } else {
            free(resultats);
        }
    // }
    return 1;
}

int Menu_Ajouter_Animal(Animal *animaux, int taille) {
    Animal animal;
    int valide = 0;

    // Générer automatiquement l'identifiant
    // l'identifiant d'un animal est le numéro de sa cage qui est le numéro de sa case dans le tableau
    // si la cage est vide, l'identifiant animal est négatif
    // sinon, il est positif
    
    int id_disponible = -1;
    for (int i = 0; i < taille; i++) {
        if (animaux[i].keyid < 0) { // Trouver une cage vide
            id_disponible = i;
            break;
        }
    }

    if (id_disponible == -1) {
        printf("[ERREUR] aucune cage disponible.\n");
        return 1;
    }
    animal.keyid = id_disponible;
    
    // Saisie du nom de l'animal
    char *nom;
    do {
        while (getchar() != '\n'); // Nettoyage du buffer d'entrée
        nom = scan_nom("Veuillez saisir le nom de l'animal (sans espaces) :", 1);
        if (nom == NULL) {
            printf("[ERREUR] Aucun nom saisi. Veuillez réessayer.\n");
        }
    } while (nom == NULL);

    strncpy(animal.nom, nom, sizeof(animal.nom) - 1);
    animal.nom[sizeof(animal.nom) - 1] = '\0'; // S'assurer de la terminaison nulle

    // Saisir l'espèce
    do {
        printf("Veuillez choisir l'espèce de l'animal :\n");
        printf("1 - Chien\n2 - Chat\n3 - Autruche\n4 - Hamster\n");
        animal.espece = 0;
        if (scanf("%d", &animal.espece) != 1 || animal.espece < 1 || animal.espece > 4) {
            printf("[ERREUR] Espèce invalide. Veuillez réessayer.\n");
            while (getchar() != '\n'); // Nettoyage du buffer
            animal.espece = 0;
        }
    } while (animal.espece < 1 || animal.espece > 4);

    // Saisir le poids
    do {
        printf("Veuillez saisir le poids de l'animal (en kg, positif) :\n");
        if (scanf("%f", &animal.weight) != 1 || animal.weight <= 0) {
            printf("[ERREUR] Le poids doit être un nombre positif. Veuillez réessayer.\n");
            while (getchar() != '\n'); // Nettoyage du buffer
        }
    } while (animal.weight <= 0);

    // Saisir l'année de naissance
    do {
        printf("Veuillez saisir l'année de naissance de l'animal :\n");
        if (scanf("%d", &animal.b_year) != 1 || animal.b_year < 1980 || animal.b_year > 2025) {
            printf("[ERREUR] Année invalide. Veuillez réessayer.\n");
            while (getchar() != '\n'); // Nettoyage du buffer
        }
    } while (animal.b_year < 1980 || animal.b_year > 2025);

    // Saisir une phrase de description
    printf("Veuillez saisir une phrase de description pour l'animal :\n");
    while (getchar() != '\n'); // Nettoyage du buffer
    if (fgets(animal.phrase, sizeof(animal.phrase), stdin) != NULL) {
        size_t len = strlen(animal.phrase);
        if (len > 0 && animal.phrase[len - 1] == '\n') {
            animal.phrase[len - 1] = '\0';
        }
    }

    // Ajouter l'animal dans la cage disponible
    animaux[id_disponible] = animal;
    return 0;
}

int Menu_Supprimer_animal(Animal * animaux, int nb_animaux) {
    if (nb_animaux == 0) {
        printf("[ERREUR] Aucun animal à adopter.\n");
        return nb_animaux;
    }

    int id;
    printf("Entrez l'ID de l'animal à faire adopter : ");
    if ((scanf("%d", &id) != 1) || id > 50 || id < 1) { // On s'assure de la robustesse du code
        printf("[ERREUR] Saisie invalide.\n");
        while (getchar() != '\n');
        return nb_animaux;
    }

    int index = -1;
    for (int i = 1; i < nb_animaux; i++) { // On commence à 1 pour ignorer la cage 0 et cherchons la bonne cage
        if (animaux[i].keyid == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Animal non trouvé.\n");
        return nb_animaux;
    }

    // Marquer la cage comme vide
    animaux[index].keyid = -1 * animaux[index].keyid;
    printf("Animal adopté, cage libérée.\n");
    return nb_animaux;
}


int Inventaire_par_espece(Animal * animaux, int nb_animaux) {
    if (nb_animaux == 0) {
        printf("Aucun animal à afficher.\n");
        return 0;
    }

    int chiens = 0, chats = 0, autruches = 0, hamsters = 0;

    for (int i = 1; i < nb_animaux; i++) {
        switch (animaux[i].espece) {
            case 1:
                chiens++;
                break;
            case 2:
                chats++;
                break;
            case 3:
                autruches++;
                break;
            case 4:
                hamsters++;
                break;
        }
    }

    printf("Inventaire :\n");
    printf("Chiens : %d\n", chiens);
    printf("Chats : %d\n", chats);
    printf("Autruches : %d\n", autruches);
    printf("Hamsters : %d\n", hamsters);
    printf("Il y a en tout : %d animaux dans le refuge.\n", chiens + chats + autruches + hamsters);

    return 0;
}

int Nettoyage_hebdomadaire(Animal *animaux, int nb_animaux) {
    int temps_total = 0;

    for (int i = 1; i < nb_animaux; i++) {
        if (animaux[i].keyid < 0) { // Cage vide
            temps_total += 2 * 7; // 2 minutes par jour
        } else {
            switch (animaux[i].espece) {
                case HAMSTERE:
                case CHAT:
                    temps_total += (10 * 7) + 20; // 10 minutes par jour + 20 minutes par semaine
                break;
                case AUTRUCHE:
                    temps_total += (20 * 7) + 45; // 20 minutes par jour + 45 minutes par semaine
                break;
                case CHIEN:
                    temps_total += (5 * 7) + 20; // 5 minutes par jour + 20 minutes par semaine
                break;
                default:
                    printf("[ERREUR] Espèce inconnue pour l'animal avec keyid %d.\n", animaux[i].keyid);
            }
        }
    }

    printf("Temps total de nettoyage hebdomadaire : %d minutes.\n", temps_total);
    return temps_total;
}

int Imprimer_animaux(Animal *animaux, int taille) {
    int cage_pleine = 0;
    printf("\n===== Liste des Animaux =====\n");
    for (int i = 1; i < taille; i++) {
        if (animaux[i].keyid < 0) {
            // Cage vide
        } else {
            cage_pleine++;
            printf("Cage %d :\n", animaux[i].keyid);
            printf("  Nom : %s\n", animaux[i].nom);
            printf("  Espèce : ");
            switch (animaux[i].espece) {
                case HAMSTERE:
                    printf("Hamster\n");
                break;
                case CHAT:
                    printf("Chat\n");
                break;
                case AUTRUCHE:
                    printf("Autruche\n");
                break;
                case CHIEN:
                    printf("Chien\n");
                break;
                default:
                    printf("Inconnue\n");
            }
            printf("  Poids : %.2f kg\n", animaux[i].weight);
            printf("  Année de naissance : %d\n", animaux[i].b_year);
            printf("  Phrase de Description : %s\n", animaux[i].phrase);
         }
    }
    if (cage_pleine == 0) {
        printf("Aucun animal dans le refuge.\n");
    }
    printf("=============================\n");
    return 0;
}

int menu_sauv_rest(Animal * animaux, int nb_animaux) {
    int choix;
    do {
        printf("\n==== Menu Sauvegarde & Restauration ====\n");
        printf("1: Sauvegarder les données\n");
        printf("2: Restaurer les données\n");
        printf("3: Retour au menu principal\n");
        printf("Votre choix : ");
        if (scanf("%d", &choix) != 1) {
            printf("[ERREUR] Saisie invalide.\n");
            while (getchar() != '\n'); // Nettoyage du buffer
            continue;
        }

        switch (choix) {
            case 1:
                if (sauvegarde(animaux, nb_animaux) == 0) {
                    printf("Données sauvegardées avec succès.\n");
                } else {
                    printf("[ERREUR] Erreur lors de la sauvegarde des données.\n");
                }
            break;
            case 2:
                if (restauration(animaux, TAILLE) == 0) {
                    printf("Données restaurées avec succès.\n");
                } else {
                    printf("[ERREUR] Erreur lors de la restauration des données.\n");
                }
            break;
            case 3:
                printf("Retour au menu principal...\n");
            return 0;
            default:
                printf("[ERREUR] Choix invalide. Veuillez entrer un numéro entre 1 et 3.\n");
        }
    } while (1);
}

int Quitter_le_Menu(Animal * animaux, int nb_animaux) {
    char choix;

    do {
        printf("Voulez-vous vraiment quitter le programme ? (O/N) : ");
        if (scanf(" %c", &choix) != 1) {
            printf("[ERREUR] Saisie invalide.\n");
            while (getchar() != '\n'); // Nettoyage du buffer
            continue;
        }

        if (choix == 'O' || choix == 'o') {
            char sauvegarde_choix;
            printf("Voulez-vous sauvegarder avant de quitter ? (O/N) : ");
            if (scanf(" %c", &sauvegarde_choix) != 1) {
                printf("[ERREUR] Saisie invalide.\n");
                while (getchar() != '\n'); // Nettoyage du buffer
                continue;
            }

            if (sauvegarde_choix == 'O' || sauvegarde_choix == 'o') {
                if (sauvegarde(animaux, nb_animaux) == 0) {
                    printf("Données sauvegardées avec succès. Au revoir !\n");
                } else {
                    printf("[ERREUR] Erreur lors de la sauvegarde des données. Au revoir !\n");
                }
            } else if (sauvegarde_choix == 'N' || sauvegarde_choix == 'n') {
                printf("Au revoir !\n");
            } else {
                printf("[ERREUR] Choix invalide. Retour au menu principal...\n");
                continue;
            }
            return 1;
        } else if (choix == 'N' || choix == 'n') {
            printf("Retour au menu principal...\n");
            return 0;
        } else {
            printf("[ERREUR] Choix invalide. Veuillez entrer O pour oui ou N pour non.\n");
        }
    } while (1);
}

// Fonction pour afficher le menu principal
void affiche_menu() {
    printf("\n==== Bienvenue dans Le menu de ChenY1 le Refuge ====\n");
    printf("1: Vous Recherchez un animal\n");
    printf("2: Vous voulez ajouter un animal\n");
    printf("3: Vous voulez supprimer adopter un animal adoptée\n");
    printf("4: Inventaire par espèce\n");
    printf("5: Faire le nettoyage hebdomadaire\n");
    printf("6: Sauvegarde & Restauration\n");
    printf("7: Afficher la liste complète des animaux\n");
    printf("8: Quitter le menu\n");
    printf("9: Crédit\n");
}
