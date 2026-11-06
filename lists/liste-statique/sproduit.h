#include <stdbool.h>
#include "../produit.h"
#define max 10


typedef struct{
    Produit p[max];
    int taille;
}Listeproduits;

Listeproduits Liste_vide();
bool est_vide(Listeproduits);
int ind_code_repeter(Listeproduits, char[]);
bool qt_stock_negatif(Produit);

Listeproduits ajouter(Listeproduits);
void afficher(Listeproduits);
Listeproduits suppr(Listeproduits, char[]);
Listeproduits acheter(Listeproduits, char[]);
Listeproduits vendre(Listeproduits, char[]);
