#include"fonctionnalite.h"

int* find_an_animal(Animal* tab, int* nb_elements,char* nom, int espece, int type){
    int* options = malloc(SIZE * sizeof(int));
    if (options == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        exit(1);
    }
    
    int j=0;
     int compteur=1;
     int a=0;
     int b=0;
    while(compteur<SIZE){
        if(strlen(nom)==strlen(tab[compteur].nom)){
            for(int i=0; i<strlen(nom); i++){
                if(nom[i]==tab[compteur].nom[i]){
                    a++;
                }
            }
            if(a==strlen(nom)){
                b++;
            }
        }
        else if(nom[0]=='\n'){
            b++;
        }
        if((type==0 && (YEAR-tab[compteur].b_year)<2)||type==-1){
            b++;
        }
        else if(type==1 && (YEAR-tab[compteur].b_year)>10){
            b++;
        }
        if((espece==tab[compteur].espece)||espece==-1){
            b++;
        }
        if(b==3){
            printf("L'animal %d correspond à votre demande.\n", compteur);
            options[j]=compteur;
            printf("ID : %d\n Nom : %s\n Espece : %d\n Année de naissance : %d\n Poids : %d\n Une phrase qui définit l'animal : %s\n",tab[compteur].keyid,tab[compteur].nom, tab[compteur].espece, tab[compteur].b_year, tab[compteur].weight, tab[compteur].phrase);
            j++;
        }
        compteur++;
        b=0;
        a=0;
    }

    *nb_elements=j;
    return options;
}

void ajout_animal(Animal* tab){
int keyid;
 char nom[25];
 int espece;
 int b_year;
 int weight;
 char phrase[255];
    int a=0;
    for(int i=1; i<SIZE; i++){
        if(tab[i].keyid>0){
            a++;
        }
    }
    if(a<50){
        do{
            printf("L'ajout d'un animal est possible\n Donnez lui un nom \n Une espece : 1) hamster  2) hautruche  3) chat  4) chien\n Année de naissance\n Poids\n Une phrase qui définit l'animal\n");
        
            if (scanf("%s", nom) != 1) {
                printf("Erreur de lecture !\n");
            }
            if (scanf("%d",&espece ) != 1) {
                printf("Erreur de lecture !\n");
            }
            if (scanf("%d",&b_year ) != 1) {
                printf("Erreur de lecture !\n");
            }
            if (scanf("%d",&weight ) != 1) {
                printf("Erreur de lecture !\n");
            }
            if (scanf("%s", phrase) != 1) {
                printf("Erreur de lecture !\n");
            }
        }while(b_year<0||b_year>YEAR|| espece <-1||espece>4);

        for(int i=1; i<SIZE; i++){
        if(tab[i].keyid<0){
            tab[i].keyid= i;
            for(int h=0;h<=strlen(nom);h++){
            tab[i].nom[h] = nom[h];
            }
            tab[i].espece=espece;
            tab[i].b_year=b_year;
            tab[i].weight=weight;
            for(int j=0;j<=strlen(phrase);j++){
            tab[i].phrase[j] = phrase[j];
            }
            i=SIZE;
        }
    }
    printf("Animal ajouté avec succès.\n");
    }
    else{
        printf("Impossible d'ajouter un animal.\n");
        exit(2);
    }

}

void delete_an_animal(Animal* tab, int id){
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
}
