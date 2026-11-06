#include <stdio.h>
#include "sfile.h"

File file_vide(){
    File q;
    q.taille = q.debut = q.fin = 0;
    return q;
}

bool est_vide(File q){
    return q.taille == 0;
}

File enfiler(File q, Fichier fich){
    if(q.taille == max2){
        printf("le file est saturee.\n");
        return q;
    }

    q.fich[q.fin] = fich;
    q.fin  = (q.fin + 1) % max2;
    q.taille++;
    printf("Enfilement reussi!\n");
    return q;
}

File defiler(File q){
    if(est_vide(q)){
        printf("le file est vide!\n");
        return q;
    }

    q.debut = (q.debut + 1) % max2;
    q.taille--;
    printf("Defilement reussi!\n");
    return q;
}

void afficher(File q){
    if(est_vide(q)){
        printf("Le file est vide, rien a afficher\n");
        return;
    }

    int i = q.debut;

    for(int cmp = 0; cmp < q.taille; cmp++){
        printf("Nom fichier : %s -- Taille : %dKo\n",q.fich[i].nom, q.fich[i].taille);
        i = (i + 1) % max2;
    }
}