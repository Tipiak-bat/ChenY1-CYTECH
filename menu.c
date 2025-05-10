#include "menu.h"

int Rechercher_animal(){
    char r_name[25] = "";
    int r_espece = -1;
    int categorie_age = 0;

    printf("\n=====Recherche=====\n");
    printf("Laissez votre saisie vide si vous souhaitez ne pas rechercher en fonction de ce critère\n");
    printf("Saisir le nom de l'animal :\n");
    // !!! il faut savoir l'expliquer,
    if (fgets(r_name, sizeof(r_name), stdin) != NULL) {
        // Supprimer le saut de ligne si présent
        size_t len = strlen(r_name);
        if (len > 0 && r_name[len - 1] == '\n') {
            r_name[len - 1] = '\0';
        }
    }
    if (strlen(r_name) == 0) {
        strcpy(r_name, "");
    }

    printf("Liste des IDs :\nIGNORER L'ESPECE = -1\n INDEFINI = 0\n HAMSTERE = 1\n AUTRUCHE = 2\n CHAT = 3\n CHIEN = 4\n");
    printf("Saisir l'ID de l'espèce :\n");
    scanf("%d", &r_espece);
    if (r_espece > 4 || r_espece < -1) {
        printf("[ERROR] Saisie invalide, retour au menu");
        return 1;
    }

    printf("Rechercher un animal (0 - IGNORER, 1 - Jeune, 2 - Adulte, 3 - Senior) : \n");
    scanf("%d", &categorie_age);
    if (categorie_age < 0 || categorie_age > 3) {
        printf("[ERROR] Saisie invalide, retour au menu\n");
        return 1;
    }

    // recherche en cours
    // Amina les valeurs par défaut sont "" pour le nom, -1 pour l'espèce, 0 pour la catégorie d'age
    // recherche_animaltab(r_name, r_espece, categorie_age);
    return 0;
  } 

Animal ajouter_Animal() {
    Animal a;
    int valide = 0;

    // Saisie de l'identifiant
    printf("Veuillez saisir l'identifiant de l'animal :\n");
    scanf("%d", &a.identifiant);

    // Saisie du nom
    do {
        valide = 1;
        printf("Veuillez saisir le nom de l'animal (sans espaces) :\n");
        scanf("%s", a.nom);
        for (int i = 0; a.nom[i] != '\0'; i++) {
            if (a.nom[i] == ' ') {
                printf("Le nom ne doit pas contenir d'espaces. Veuillez réessayer.\n");
                valide = 0;
                break;
            }
        }
    } while (valide != 1);

    // Saisie de l'espèce
    do {
        printf("Veuillez choisir l'espèce de l'animal :\n");
        printf("1 - Chien\n2 - Chat\n3 - Autruche\n4 - Hamster\n");
        scanf("%d", &a.espece);
        if (a.espece < 1 || a.espece > 4) {
            printf("Espèce invalide. Veuillez réessayer.\n");
        }
    } while (a.espece < 1 || a.espece > 4);

    // Saisie du poids
    do {
        printf("Veuillez saisir le poids de l'animal (en kg, positif) :\n");
        scanf("%f", &a.poids);
        if (a.poids <= 0) {
            printf("Le poids doit être un nombre positif. Veuillez réessayer.\n");
        }
    } while (a.poids <= 0);

    // Saisie de l'année de naissance
    do {
        printf("Veuillez saisir l'année de naissance de l'animal :\n");
        scanf("%d", &a.annee_naissance);
        if (a.annee_naissance < 1980 || a.annee_naissance > 2025) {
            printf("Année invalide. Veuillez réessayer.\n");
        }
    } while (a.annee_naissance < 1980 || a.annee_naissance > 2025);

    // Déterminer la catégorie d'âge
    int annee_actuelle = 2023;
    int age = annee_actuelle - a.annee_naissance;
    if (age <= 2) {
        snprintf(a.categorie_age, sizeof(a.categorie_age), "Junior");
    } else if (age > 10) {
        snprintf(a.categorie_age, sizeof(a.categorie_age), "Senior");
    } else {
        snprintf(a.categorie_age, sizeof(a.categorie_age), "Adulte");
    } // snprintf c comme un printf pour une variable mais avec une limite de mots pour eviter les bug 

    // Affichage final
    printf("\nAnimal ajouté :\n");
    printf("Identifiant : %d\n", a.identifiant);
    printf("Nom : %s\n", a.nom);
    printf("Espèce : %d\n", a.espece);
    printf("Année de naissance : %d\n", a.annee_naissance);
    printf("Poids : %.2f kg\n", a.poids);
    printf("Catégorie d'âge : %s\n", a.categorie_age);

    return a;
}


int Supprimer_animal(Animal animaux[], int nb_animaux) {
    if (nb_animaux == 0) {
        printf("Aucun animal à supprimer.\n");
        return nb_animaux;
    }

    int id;
    printf("Entrez l'ID de l'animal à supprimer : ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < nb_animaux; i++) {
        if (animaux[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) { //  index c'est une variable utilisée pour stocker la position de l'animal à supprimer dans le tableau animaux[].
        printf("Animal non trouvé.\n");
        return nb_animaux;
    }

    for (int i = index; i < nb_animaux - 1; i++) {
        animaux[i] = animaux[i + 1];
    }

    printf("Animal supprimé avec succès.\n");
    return nb_animaux - 1;
}
  return 0;
}

    // Fonction qui retourne le nombre d'animaux par espèce VARIANTE
int Inventaire_par_espece(Animal animaux[], int nb_animaux) {
    if (nb_animaux == 0) {
        printf("Aucun animal à afficher.\n");
        return 0;
    }

    int chiens = 0, chats = 0, autruches = 0, hamsters = 0;

    for (int i = 0; i < nb_animaux; i++) {
        switch (animaux[i].species) {
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

    // Retourne le nombre total d'animaux dans l'inventaire
    printf("Inventaire :\n");
    printf("Chiens : %d\n", chiens);
    printf("Chats : %d\n", chats);
    printf("Autruches : %d\n", autruches);
    printf("Hamsters : %d\n", hamsters);
    
    return 0;  // Indicateur de réussite ou d'achèvement de la fonction
}


  return 0;
}
int Nettoyage_hebdomadaire(Animal animaux[], int nb_animaux) { // VARIANTE 
    int temps_total = 0;

    for (int i = 0; i < nb_animaux; i++) {
        switch (animaux[i].species) {
            case 1: 
                temps_total += (5 * 7) + 20;
                break;  // Chien
            case 2: 
                temps_total += (10 * 7) + 20; 
                break; // Chat
            case 3:
                temps_total += (20 * 7) + 45;
                break; // Autruche
            case 4:
                temps_total += (10 * 7) + 20; 
                break; // Hamster
        }
    }

    int cages_vides = 10 - nb_animaux;
    if (cages_vides > 0) {
        temps_total += cages_vides * (2 * 7); // 2 minutes/jour/cage vide
    }

    printf("Temps total de nettoyage hebdomadaire : %d minutes.\n", temps_total);
    return temps_total;
}

  return 0;
}

int Quitter_le_Menu(){
  
  return 0;

}


do {                           // faire boucle do....while pour que le menu s'affiche plusieurs fois
void affiche_menu () {
  printf （"\n====Bienvenue dans Le menu de ChenY1 le Refuge====\n"）；
  printf("1: Vous Recherchez un animal\n");
  printf("2: Vous voulez ajouter un animal\n");
  printf("3: Vous voulez supprimer un animal\n");
  printf("4: Inventaire par espèce\n"); // ler variante inventaire nombre decroissant
  printf("5: Faire le nettoyage hebdomaire\n"); //2eme variante DAY CLEAN
  printf("6: Quitter le menu\n");
  printf("7: Crédit\n");
}

// dans le int main 

int choix; 

affiche_menu();
printf("Quel est votre choix\n");     // on regarde ce qu'a choisie l'utilisateur
scanf ("%d", &choix);
                                     // utiliser switch case car il y a plusieurs valeur
switch (choix) {
        case 1 : 
               Rechercher_animal();
               break;
        case 2 : 
               Ajouter_animal();
               break ;
        case 3 :
               Supprimer_animal();
               break;
        case 4 : 
               Inventaire_par_espece();
               break;
        case 5 :
               Nettoyage_hebdomadaire();
               break; 
        case 6 : 
               Quitter_le_Menu();
               break;
default:
        printf("Erreur: veuiller saisir un numéro entre 1 et 6");
while(choix > 0 || choix > 6);                       // ne pas quitter tant que l'utilisateur n'a pas choisie un numéro entre 1 et 6
}
return 0; 
}
