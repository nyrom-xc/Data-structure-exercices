#include <stdio.h>
#include <stdlib.h>
#include "sproduit.h"
#define max 10

int main(){
    Listeproduits L = Liste_vide();
    int option;
    char code[max];

    while (true){
        printf("\n\n");
        printf("===Bienvenu dans votre liste de produits:===\n");
        printf("===Les operations de gestion que vous avez:===\n");
        printf("1 --> Ajouter un produit\n2 --> Afficher la liste de produits\n3 --> Supprimer un produit\n4 --> Acheter un produit\n5 --> Vendre un produit\n6 --> Quitter");
        printf("\n");

        printf("\nEnter l'option que vous voulez : ");
        scanf("%d", &option);

        switch(option){
            case 1:
                L = ajouter(L);
                break;
            
            case 2:
                afficher(L);
                break;

            case 3:
                printf("Entrer le code produit : ");
                scanf("%s", code);
                L = suppr(L, code);
                break;

            case 4:
                printf("Entrer le code produit : ");
                scanf(" %s", code);
                L = acheter(L, code);
                break;

            case 5:
                printf("Entrer le code produit : ");
                scanf(" %s", code);
                L = vendre(L, code);
                break;

            case 6:
                printf("Vous avez quitte le programme...");
                exit(0);

            default:
                printf("Entrer une option valide!");
                break;
        }
    }

    return 0;
}
