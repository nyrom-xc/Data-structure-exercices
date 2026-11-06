#include <stdio.h>
#include "pile.h"

int main(){
    Pile p = pile_vide();

    p = empiler(p, 'r');
    afficher(p);
    p = empiler(p, 'd');
    p = empiler(p, 's');
    afficher(p);

    p = depiler(p);
    afficher(p);
    p = depiler(p);
    afficher(p);
    p = depiler(p);
    p = depiler(p);
    afficher(p);

    return 0;
}