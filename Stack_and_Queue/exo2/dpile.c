#include <stdio.h>
#include <stdlib.h>
#include "dpile.h"

Pile pile_vide(){
    return NULL;
}

bool est_vide(Pile p){
    return p == NULL;
}
Pile empiler(Pile p, char cara){
    Noued * n = malloc(sizeof(Noued));
    n->cara = cara;
    n->svt = p;
    p = n;
    return p;
}

Pile depiler(Pile p){
    if(est_vide(p)){
        printf("la pile est vide!");
        return p;
    }
    
    Pile tmp = p;
    p = p->svt;
    free(tmp);
    return p;
}

Pile vider_pile(Pile p){
    if(est_vide(p)){
        printf("le pile est vide\n");
        return p;
    }
    while(!est_vide(p)){
        p = depiler(p);
    }
    printf("le Pile est vider avec succes!\n");
    return p;
}

void afficher(Pile p){
    if(est_vide(p)){
        printf("La pile est vide, rien a afficher!\n");
        return;
    }

    while(p){
        printf("%c\t",p->cara);
        p = p->svt;
    }
    printf("\n");
}