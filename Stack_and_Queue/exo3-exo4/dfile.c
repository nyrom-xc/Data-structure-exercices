#include <stdio.h>
#include <stdlib.h>
#include "dfile.h"

File file_vide(){
    File q;
    q.debut = q.fin = NULL;
    return q;
}

bool est_vide(File q){
    return q.debut == NULL; 
}

File enfiler(File q, Fichier fich){
    Noued * n = malloc(sizeof(Noued));
    n->val = fich;
    n->svt = NULL;

    if(est_vide(q)){
        q.debut = q.fin = n;
        printf("Enfilement reussi!\n");
        return q;
    }
    q.fin->svt = n;
    q.fin = n;
    printf("Enfilement reussi!\n");
    return q;
}

File defiler(File q){
    if(est_vide(q)){
        printf("le file est vide!\n");
        return q;
    }

    Noued * old = q.debut;
    q.debut = q.debut->svt;

    if(q.debut == NULL){
        q.fin = NULL;
    }

    free(old);
    printf("Defilement reussi!\n");
    return q;

}

void afficher(File q){
    if(est_vide(q)){
        printf("Le file est vide, rien a afficher\n");
        return;
    }

    while(!est_vide(q)){
        printf("Nom fichier : %s -- Taille : %dKo\n",q.debut->val.nom, q.debut->val.taille);
        q.debut = q.debut->svt;
    }
}