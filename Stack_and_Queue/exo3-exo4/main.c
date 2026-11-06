#include "sfile.h"

int main(){
    File q = file_vide();
    afficher(q);
    q = enfiler(q, (Fichier){"houssam.txt", 125});
    afficher(q);
    q = enfiler(q, (Fichier){"hassan.js", 15});
    q = enfiler(q, (Fichier){"moha.docx", 135});
    q = enfiler(q, (Fichier){"simo.md", 207});
    afficher(q);
    q = enfiler(q, (Fichier){"imad.md", 207});
    q = enfiler(q, (Fichier){"monir.md", 207});
    afficher(q);

    q = defiler(q);
    afficher(q);
    q = enfiler(q, (Fichier){"monir.md", 207});
    afficher(q);
    q = defiler(q);
    q = defiler(q);
    q = defiler(q);
    q = defiler(q);
    afficher(q);


    return 0;
}