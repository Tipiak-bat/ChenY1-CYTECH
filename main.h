#ifndef MAIN_H

#define MAIN_H

   #include <stdio.h>
   #include <string.h>
   #include <stdlib.h>
   #include <time.h>
   #define SIZE 50
typedef struct
 {
    int keyid;
    char nom[25];
    int espece;
    int b_year;
    int weight;
    char phrase[255];
 } Animal;

 Animal animals[SIZE];

#endif //MAIN_H
