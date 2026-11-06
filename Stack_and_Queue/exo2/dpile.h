#include <stdbool.h>

typedef struct n{
    char cara;
    struct n * svt;
}Noued;

typedef Noued * Pile;

Pile pile_vide();
bool est_vide(Pile);
Pile empiler(Pile, char);
Pile depiler(Pile);
Pile vider_pile(Pile);
void afficher(Pile);
