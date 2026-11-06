#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dproduit.h"

Listeproduits Liste_vide(){
    return NULL;
}

int longueur(Listeproduits L){
    int taille = 0;
    while(L){
        taille++;
        L = L->svt;
    }
    return taille;
}

bool est_vide(Listeproduits L){
    return L == NULL;
}

Place ind_code_repeter(Listeproduits L, char code[]){
    while(L){
        if(strcmp(L->p.code, code) == 0) return L;
        L = L->svt;
    }
    return NULL;
}

bool qt_stock_negatif(Produit p){
    return (p.qt_stock < 0)? true : false;
}

Listeproduits ajouter(Listeproduits L){
    Place n = malloc(sizeof(Noued));
    n->svt = NULL;
    do{
        printf("Entre le code de produit : ");
        scanf(" %9s", n->p.code);

        if(ind_code_repeter(L,n->p.code) != NULL){
            printf("Le code produit deja existe , veuillez entrer un code valide!\n");
            continue;
        }

        printf("\nEntrer l'intutile de produit : ");
        scanf(" %9s", n->p.intitule);
        printf("\nEntrer la quantite de produit en stock : ");
        scanf("%d", &n->p.qt_stock);
    }while(ind_code_repeter(L,n->p.code) != NULL || qt_stock_negatif(n->p));

    if(est_vide(L)){
        L = n;
    }

    else{
        Place header = L;
        while(L->svt != NULL){
             L = L->svt;
        }
        L->svt = n;
        L = header;
    }
    printf("le produit %s ete ajouter avec success",n->p.intitule);
    return L;
}

void afficher(Listeproduits L){
    if(est_vide(L)){
        printf("--La liste de produits est vide!--\n");
        return;
    }
    //J'ai utiliser le "-" pour aligner le text à droite
    printf("%-8s | %-15s | %-10s | %-10s|\n","Produit","Code produit", "Intitule", "Qt_stock");
    printf("----------------------------------------------------|\n");
    int i = 1;
    Place current = L;
    while(current){
        printf("%-8d | %-15s | %-10s | %-10d|\n",i, current->p.code, current->p.intitule, current->p.qt_stock);
        i++;
        current = current->svt;
    }
}

Listeproduits suppr(Listeproduits L, char code[]){
    if(est_vide(L)){
        printf("--La liste est vide!--");
        return L;
    }

    Place r = ind_code_repeter(L, code);

    if (r == NULL){
        printf("Ce code ne trouve pas dans la liste des produits");
        return L;
    }

    if( r == L){
        Listeproduits nv_L = L->svt;
        free(r);
        printf("L'operation ete execute avec success");
        return nv_L;
    }
    
    Place predecesseur = L;
    while(predecesseur->svt != r){
        predecesseur = predecesseur->svt;
    }

    predecesseur->svt = r->svt;
    free(r);

    printf("L'operation ete execute avec success");
    return L;
}

Listeproduits acheter(Listeproduits L, char code[]){
    if(est_vide(L)){
        printf("--La liste est vide!--\n");
        printf("Vous devez ajouter un produit dans la liste pour l'acheter.\n");
        return L;
    }

    Place r = ind_code_repeter(L, code);
    int qt;

    if(r == NULL){
        printf("le code produit ne trouve pas dans la liste !");
        return L;
    }

    if(r->p.qt_stock == 0){
        printf("Alert : Le produit est sold out!\n");
    }

    do{
        printf("Entrer la quantite que vous voulez achetez : ");
        scanf("%d", &qt);
    }while(qt <= 0);

    r->p.qt_stock += qt;
    printf("L'operation d'achat est valide");
    return L;
}

Listeproduits vendre(Listeproduits L, char code[]){
    if(est_vide(L)){
        printf("--La liste est vide!--\n");
        printf("Vous devez ajouter un produit dans la liste pour le vender.\n");
        return L;
    }
    Place r = ind_code_repeter(L, code);
    int qt;
    if(r == NULL){
        printf("le code produit ne trouve pas dans la liste !");
        return L;
    }

    if(r->p.qt_stock == 0){
        printf("Le produit est sold out!\n");
        return L;
    }

    do{
        printf("Entrer la quantite que vous voulez vendez : ");
        scanf("%d", &qt);
    }while(qt <= 0 || qt > r->p.qt_stock);

    r->p.qt_stock -= qt;
    printf("L'operation de vende est valide");
    return L;
}