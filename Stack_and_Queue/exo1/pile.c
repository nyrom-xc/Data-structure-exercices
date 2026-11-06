#include <stdio.h>
#include "pile.h"

Pile pile_vide(){
    Pile p;
    p.sommet = -1;
    return p;
}

bool est_vide(Pile p){
    return p.sommet == -1;
}

Pile empiler(Pile p, char cara){
    
     if(p.sommet == max-1){
        printf("Le pile est saturee !\n");
        return p;
    }

    p.tab[++p.sommet] = cara;
    printf("L'empilation est reussite.\n");
    return p;
}

Pile depiler(Pile p){
    if(est_vide(p)){
        printf("Le pile est vide!\n");
        return p;
    }

    p.sommet--;
    return p;
}

void afficher(Pile p){
    if(est_vide(p)){
        printf("le pile est vide\n");
        return;
    }

    int arret = p.sommet+1;

    for(int i = 0; i<arret; i++){
        printf("%c\t",p.tab[i]);
    }
    printf("\n");
}