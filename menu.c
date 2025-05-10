#include "menu.h"

int Rechercher_animal() {
    // on met des valeurs par défaut
    char r_name[25] = "";
    int r_espece = -1;
    int r_age_type = -1; // -1 = pas de critère, 0 = jeune (<2 ans), 1 = senior (>10 ans)

    printf("\n===== Recherche =====\n");
    printf("Laissez votre saisie vide si vous souhaitez ne pas rechercher en fonction de ce critère\n");

    // Critère : Nom
    printf("Saisir le nom de l'animal :\n");
    while (getchar() != '\n'); // Nettoyage du buffer
    if (fgets(r_name, sizeof(r_name), stdin) != NULL) {
        size_t len = strlen(r_name);
        if (len > 0 && r_name[len - 1] == '\n') {
            r_name[len - 1] = '\0';
        }
    }

    // Critère : Espèce
    printf("Liste des IDs :\nIGNORER L'ESPECE = -1\n HAMSTERE = 1\n AUTRUCHE = 2\n CHAT = 3\n CHIEN = 4\n");
    printf("Saisir l'ID de l'espèce :\n");
    if (scanf("%d", &r_espece) != 1 || r_espece > 4 || r_espece < -1) {
        printf("[ERROR] Saisie invalide, retour au menu\n");
        while (getchar() != '\n'); // Nettoyage du buffer
        return 1;
    }

    // Critère : Type d'âge
    printf("Rechercher par type d'âge :\n");
    printf("IGNORER = -1, JEUNE (<2 ans) = 0, SENIOR (>10 ans) = 1\n");
    if (scanf("%d", &r_age_type) != 1 || r_age_type < -1 || r_age_type > 1) {
        printf("[ERROR] Saisie invalide, retour au menu\n");
        while (getchar() != '\n'); // Nettoyage du buffer
        return 1;
    }
    
    // recherche_factuel(r_espece, r_name, r_agetype);
    return 0;
}

int Ajouter_Animal(Animal * animaux, int size) {
    Animal animal;
    int valide = 0;

    printf("Veuillez saisir l'identifiant de l'animal :\n");
    if ((scanf("%d", &animal.keyid) != 1) || animal.keyid < 1 || animal.keyid > 50) {
        printf("[ERROR] Saisie invalide pour l'identifiant.\n");
        while (getchar() != '\n'); // Nettoyage du buffer
        return 1;
    }

    do {
        valide = 1;
        printf("Veuillez saisir le nom de l'animal (sans espaces) :\n");
        if (scanf("%s", animal.nom) != 1) {
            printf("[ERROR] Saisie invalide pour le nom.\n");
            return 1;
        }
        for (int i = 0; animal.nom[i] != '\0'; i++) {
            if (animal.nom[i] == ' ') {
                printf("Le nom ne doit pas contenir d'espaces. Veuillez réessayer.\n");
                valide = 0;
                break;
            }
        }
    } while (valide != 1);

    do {
        printf("Veuillez choisir l'espèce de l'animal :\n");
        printf("1 - Chien\n2 - Chat\n3 - Autruche\n4 - Hamster\n");
        if (scanf("%d", &animal.espece) != 1 || animal.espece < 1 || animal.espece > 4) {
            printf("Espèce invalide. Veuillez réessayer.\n");
            while (getchar() != '\n'); // Nettoyage du buffer
        }
    } while (animal.espece < 1 || animal.espece > 4);

    do {
        printf("Veuillez saisir le poids de l'animal (en kg, positif) :\n");
        if (scanf("%f", &animal.weight) != 1 || animal.weight <= 0) {
            printf("Le poids doit être un nombre positif. Veuillez réessayer.\n");
            while (getchar() != '\n'); // Nettoyage du buffer
        }
    } while (animal.weight <= 0);

    do {
        printf("Veuillez saisir l'année de naissance de l'animal :\n");
        if (scanf("%d", &animal.b_year) != 1 || animal.b_year < 1980 || animal.b_year > 2025) {
            printf("Année invalide. Veuillez réessayer.\n");
            while (getchar() != '\n'); // Nettoyage du buffer
        }
    } while (animal.b_year < 1900 || animal.b_year > 2025);

    for (int i = 1; i < size; i++) {
        if (animaux[i].keyid < 0) { // Trouver une cage vide
            animaux[i] = animal;
            return 0;
        }
    }

    printf("Erreur : aucune cage disponible.\n");
    return 1;
}

int Supprimer_animal(Animal * animaux, int nb_animaux) {
    if (nb_animaux == 0) {
        printf("Aucun animal à adopter.\n");
        return nb_animaux;
    }

    int id;
    printf("Entrez l'ID de l'animal à faire adopter : ");
    if (scanf("%d", &id) != 1) {
        printf("[ERROR] Saisie invalide.\n");
        while (getchar() != '\n'); // Nettoyage du buffer
        return nb_animaux;
    }
   
    int index = -1;
    for (int i = 1; i < nb_animaux; i++) {
        if (animaux[i].keyid == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Animal non trouvé.\n");
        return nb_animaux;
    }

    for (int i = index; i < nb_animaux - 1; i++) {
        animaux[i] = animaux[i + 1];
    }

    printf("Animal adoptée supprimé de la base de données avec succès.\n");
    return nb_animaux - 1;
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

    return 0;
}

int Nettoyage_hebdomadaire(Animal *animaux, int nb_animaux) {
    int temps_total = 0;

    for (int i = 1; i < SIZE; i++) {
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
                    printf("Espèce inconnue pour l'animal avec keyid %d.\n", animaux[i].keyid);
            }
        }
    }

    printf("Temps total de nettoyage hebdomadaire : %d minutes.\n", temps_total);
    return temps_total;
}

int Imprimer_animaux(Animal *animaux, int taille) {
    printf("\n===== Liste des Animaux =====\n");
    for (int i = 1; i < taille; i++) {
        if (animaux[i].keyid < 0) {
            printf("Cage %d : Vide\n", -animaux[i].keyid);
        } else {
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
            printf("[ERROR] Saisie invalide.\n");
            while (getchar() != '\n'); // Nettoyage du buffer
            continue;
        }

        switch (choix) {
            case 1:
                if (sauvegarde(animaux, nb_animaux) == 0) {
                    printf("Données sauvegardées avec succès.\n");
                } else {
                    printf("Erreur lors de la sauvegarde des données.\n");
                }
            break;
            case 2:
                if (restauration(animaux, SIZE) == 0) {
                    printf("Données restaurées avec succès.\n");
                } else {
                    printf("Erreur lors de la restauration des données.\n");
                }
            break;
            case 3:
                printf("Retour au menu principal...\n");
            return 0;
            default:
                printf("[ERROR] Choix invalide. Veuillez entrer un numéro entre 1 et 3.\n");
        }
    } while (1);
}

int Quitter_le_Menu(Animal * animaux, int nb_animaux) {
    char choix;

    do {
        printf("Voulez-vous vraiment quitter le programme ? (O/N) : ");
        if (scanf(" %c", &choix) != 1) {
            printf("[ERROR] Saisie invalide.\n");
            while (getchar() != '\n'); // Nettoyage du buffer
            continue;
        }

        if (choix == 'O' || choix == 'o') {
            char sauvegarde_choix;
            printf("Voulez-vous sauvegarder avant de quitter ? (O/N) : ");
            if (scanf(" %c", &sauvegarde_choix) != 1) {
                printf("[ERROR] Saisie invalide.\n");
                while (getchar() != '\n'); // Nettoyage du buffer
                continue;
            }

            if (sauvegarde_choix == 'O' || sauvegarde_choix == 'o') {
                if (sauvegarde(animaux, nb_animaux) == 0) {
                    printf("Données sauvegardées avec succès. Au revoir !\n");
                } else {
                    printf("Erreur lors de la sauvegarde des données. Au revoir !\n");
                }
            } else if (sauvegarde_choix == 'N' || sauvegarde_choix == 'n') {
                printf("Au revoir !\n");
            } else {
                printf("Choix invalide. Retour au menu principal...\n");
                continue;
            }
            return 1;
        } else if (choix == 'N' || choix == 'n') {
            printf("Retour au menu principal...\n");
            return 0;
        } else {
            printf("Choix invalide. Veuillez entrer O pour oui ou N pour non.\n");
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
    printf("7: Afficher la liste des animaux\n");
    printf("8: Quitter le menu\n");
    printf("9: Crédit\n");
}
