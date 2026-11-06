#include <stdbool.h>
#define max 7

typedef struct{
    char tab[max];
    int sommet;
}Pile;

Pile pile_vide();
bool est_vide(Pile);
Pile empiler(Pile, char);
Pile depiler(Pile);
void afficher(Pile);