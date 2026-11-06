#include <stdbool.h>
#include "../produit.h"

typedef struct node{
    Produit p;
    struct node * svt;
}Noued;

typedef Noued * Listeproduits;
typedef Noued * Place;

Listeproduits Liste_vide();
bool est_vide(Listeproduits);
int longueur(Listeproduits);

Place ind_code_repeter(Listeproduits, char[]);
bool qt_stock_negatif(Produit);

Listeproduits ajouter(Listeproduits);
void afficher(Listeproduits);
Listeproduits suppr(Listeproduits, char[]);
Listeproduits acheter(Listeproduits, char[]);
Listeproduits vendre(Listeproduits, char[]);
