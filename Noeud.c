#include "include/Noeud.h"
#include "include/ArbreForet.h"


struct Noeud * newNoeud(struct cellule * c) {
    struct Noeud * newNoeud = (struct Noeud*)malloc(sizeof(struct Noeud));
    newNoeud->cellule = c;
    newNoeud->numFils = 0;
    return newNoeud;
}

void ajtFils(struct Noeud * parent, struct Noeud * fils) {
    parent->fils[parent->numFils] = fils;
    parent->numFils++;
}

void libererNoeud(struct Noeud * n) {
    for (int i = 0; i < n->numFils; i++) {
        libererNoeud(n->fils[i]);
    }
    free(n);
}

int maxProfondeur(struct Noeud * n) {
    if (n == NULL) {
        return 0;
    }
    int maxProf = 0;
    for (int i = 0; i < n->numFils; ++i) {
        int profFils = maxProfondeur(n->fils[i]);
        if (profFils > maxProf) {
            maxProf = profFils;
        }
    }
    return 1 + maxProf;
}
