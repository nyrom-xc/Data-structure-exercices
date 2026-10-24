#include <stdio.h>
#include <string.h> 
#include "sproduit.h"

Listeproduits Liste_vide(){
    Listeproduits L;
    L.taille = 0;
    return L;
}

bool est_vide(Listeproduits L){
    return L.taille == 0;
}

int ind_code_repeter(Listeproduits L, char code[]){
    for(int i =0; i<L.taille; i++)
        if(strcmp(L.p[i].code, code) == 0) return i;

    return -1;
}

bool qt_stock_negatif(Produit p){
    return (p.qt_stock < 0)? true : false;
}

Listeproduits ajouter(Listeproduits L){
    if(L.taille == max){
        printf("La liste de produits est saturée!");
        return L;
    }

    do{
        printf("Entre le code de produit : ");
        scanf(" %9s", L.p[L.taille].code);

        if(ind_code_repeter(L,L.p[L.taille].code) != -1){
            printf("Le code produit existe deja , veuillez entrer un code valide!\n");
            continue;
        }

        printf("\nEntrer l'intutile de produit : ");
        scanf(" %9s", L.p[L.taille].intitule);
        printf("\nEntrer la quantite de produit en stock : ");
        scanf("%d", &L.p[L.taille].qt_stock);
    }while(ind_code_repeter(L,L.p[L.taille].code) != -1 || qt_stock_negatif(L.p[L.taille]));
    L.taille++;
    printf("le produit %s ete ajouter avec success",L.p[L.taille].intitule);
    return L;
}

void afficher(Listeproduits L){
    if(est_vide(L)){
        printf("--La liste de produits est vide!--");
        return ;
    }
    //J'ai utiliser le "-" pour aligner le text à droite
    printf("%-8s | %-15s | %-10s | %-10s|\n","Produit","Code produit", "Intitule", "Qt_stock");
    printf("----------------------------------------------------|\n");

    for(int i = 0; i<L.taille; i++){
        printf("%-8d | %-15s | %-10s | %-10d|\n",i+1, L.p[i].code, L.p[i].intitule, L.p[i].qt_stock);
    }
}

Listeproduits suppr(Listeproduits L, char code[]){
    if(est_vide(L)){
        printf("--La liste est vide!--");
        return L;
    }

    int r = ind_code_repeter(L, code);

    if(r == -1){
        printf("Ce code ne trouve pas dans la liste des produits");
        return L;
    }
    
    for(int i = r; i<L.taille; i++)
        L.p[i] = L.p[i+1];

    L.taille--;
    printf("L'operation est execute avec success!");
    return L;
}

Listeproduits acheter(Listeproduits L, char code[]){
    int r = ind_code_repeter(L, code);
    int qt;

    if(est_vide(L)){
        printf("--La liste est vide!--\n");
        printf("Vous devez ajouter un produit dans la liste pour l'acheter.\n");
        return L;
    }

    if(r == -1){
        printf("le code produit ne trouve pas dans la liste !");
        return L;
    }

    if(L.p[r].qt_stock == 0){
        printf("Alert : Le produit est sold out!\n");
    }

    do{
        printf("Entrer la quantite que vous voulez achetez : ");
        scanf("%d", &qt);
    }while(qt <= 0);

    L.p[r].qt_stock += qt;
    printf("L'operation d'achat est valide");
    return L;
}

Listeproduits vendre(Listeproduits L, char code[]){
    int r = ind_code_repeter(L, code);
    int qt;

    if(est_vide(L)){
        printf("--La liste est vide!--");
        return L;
    }

    if(r == -1){
        printf("le code produit ne trouve pas !");
        return L;
    }

    if(L.p[r].qt_stock == 0){
        printf("Le produit est sold out!");
        return L;
    }

    do{
        printf("Entrer la quantite que vous voulez vendez : ");
        scanf("%d", &qt);
    }while(qt <= 0 || qt > L.p[r].qt_stock);

    L.p[r].qt_stock -= qt;
    printf("L'operation de vende est valide");
    return L;
}
