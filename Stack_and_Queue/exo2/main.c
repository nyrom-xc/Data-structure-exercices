#include "dpile.h"

int  main(){
    Pile p = pile_vide();
    p = empiler(p, 'h');
    afficher(p);
    p = empiler(p, 'r');
    p = empiler(p, 's');
    p = empiler(p, 'd');
    afficher(p);
    p = vider_pile(p);
    afficher(p);

    return 0;
}