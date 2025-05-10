#include "sauvegarde.h"

int sauvegarde(Animal *animals, int size) {
     if (animals == NULL || size <= 0) {
          printf("[ERROR] Paramètres invalides : animals est NULL ou size <= 0\n");
          return 1;
     }

     FILE *fichier = fopen("animal.txt", "w");
     if (fichier == NULL) {
          printf("[ERROR] Impossible d'ouvrir le fichier animal.txt\n");
          return 1;
     }

     printf("[LOGS] Sauvegarde en cours... (ne pas éteindre le programme)\n");
     for (int i = 0; i < size; i++) {
          if (animals[i].keyid < 0) {
               continue;
          }

          if (animals[i].nom == NULL || animals[i].phrase == NULL) {
               printf("[ERROR] Données invalides pour l'animal à l'index %d\n", i);
               fclose(fichier);
               return 1;
          }

          if (fprintf(fichier, "%d %s %d %d %d %s\n\n",
                      animals[i].keyid,
                      animals[i].nom,
                      animals[i].espece,
                      animals[i].b_year,
                      animals[i].weight,
                      animals[i].phrase) < 0) {
               printf("[ERROR] Erreur lors de l'écriture dans le fichier\n");
               fclose(fichier);
               return 1;
                      }
     }

     if (fclose(fichier) != 0) {
          printf("[ERROR] Erreur lors de la fermeture du fichier animal.txt\n");
          return 1;
     }

     printf("[LOGS] Sauvegarde terminée !\n");
     return 0;
}


int restauration(Animal *animals, int size) {
     if (animals == NULL || size <= 0) {
          printf("[ERROR] Paramètres invalides : animals est NULL ou size <= 0\n");
          return 1;
     }

     FILE *fichier = fopen("animal.txt", "r");
     if (fichier == NULL) {
          printf("[ERROR] Impossible d'ouvrir le fichier animal.txt\n");
          return 1;
     }

     printf("[LOGS] Restauration en cours...\n");
     int i = 0;
     while (i < size && fscanf(fichier, "%d %s %d %d %d %s\n",
                               &animals[i].keyid,
                               animals[i].nom,
                               &animals[i].espece,
                               &animals[i].b_year,
                               &animals[i].weight,
                               animals[i].phrase) == 6) {
          i++;
                               }

     if (fclose(fichier) != 0) {
          printf("[ERROR] Erreur lors de la fermeture du fichier animal.txt\n");
          return 1;
     }

     printf("[LOGS] Restauration terminée ! %d animaux chargés.\n", i);
     return 0;
}
