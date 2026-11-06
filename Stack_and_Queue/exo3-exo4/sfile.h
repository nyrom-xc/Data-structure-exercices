#include <stdbool.h>
#define max 20
#define max2 5

typedef struct{
    char nom[max];
    int taille;
}Fichier;

typedef struct{
    Fichier fich[max2];
    int debut;
    int fin;
    int taille;

}File;

File file_vide();
bool est_vide(File);
File enfiler(File, Fichier);
File defiler(File);
void afficher(File);