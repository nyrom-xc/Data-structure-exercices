#include <stdbool.h>
#define max 20

typedef struct{
    char nom[max];
    int taille;
}Fichier;

typedef struct n{
    Fichier val;
    struct n * svt;
}Noued;

typedef struct{
    Noued * debut;
    Noued * fin;
}File;

File file_vide();
bool est_vide(File);
File enfiler(File, Fichier);
File defiler(File);
void afficher(File);