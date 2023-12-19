#include "include/ArbreForet.h"

//Liste des positions possibles pour nos voisins
int positions[8][2]  = {
        {-1,-1},{-1,0},{-1,1},
        {0,-1}, {0,1},
        {1,-1},{1,0},{1,1}
};

struct ArbreForet * ArbreVide() {
    struct ArbreForet * arbre = malloc(sizeof(struct ArbreForet));
    if (arbre == NULL){
        perror("erreur malloc...\n");
    }
    arbre->racine = NULL;
    return arbre;
}

void libererArbre(struct ArbreForet * a) {
    if (a->racine != NULL) {
        libererNoeud(a->racine);
        a->racine = NULL;  
    }
}


int profondeur(struct ArbreForet * a) {
    return maxProfondeur(a->racine);
}

int estPresentDansArbre(struct Noeud * arbre, int x, int y) {
    if (arbre == NULL) {
        return 0;
    }
    // Parcourir récursivement les fils de l'arbre
    for (int i = 0; i < arbre->numFils; i++) {
        if(arbre->fils[i]->cellule == arbre->cellule)
            return 0;
        if (estPresentDansArbre(arbre->fils[i], x, y)) {
            return 1;
        }
    }
    return 0;
}

void construireArbre(struct foret* f, int x, int y, struct Noeud* parent) {
    for (int i = 0; i < 8; i++) {
        int voisinX = x + positions[i][0];
        int voisinY = y + positions[i][1];

        if (voisinX >= 0 && voisinX < f->tab.l && voisinY >= 0 && voisinY < f->tab.L) {
            if (!estPresentDansArbre(parent, voisinX, voisinY)) {
                struct Noeud * fils = newNoeud(&f->ensemble[voisinX][voisinY]);
                parent->fils[parent->numFils++] = fils;

                // Récursivement construire l'arbre pour le voisin
                construireArbre(f, voisinX, voisinY, fils);
            }
        }
    }
}

struct ArbreForet * ForetToArbre(struct foret * f, int Ax, int Ay) {
    struct ArbreForet* arbre = ArbreVide();
    arbre->racine = newNoeud(&f->ensemble[Ax][Ay]);
    construireArbre(f, Ax, Ay, arbre->racine);
    return arbre;
}



void SimulePropa(struct ArbreForet * a, int Ax, int Bx, int Ay, int By) {

}

int nbTourPropa(struct ArbreForet * a, int x, int y) {
    return 0;
}
int longeurChemin(struct ArbreForet * a, int x, int y) {
    return 0;
}