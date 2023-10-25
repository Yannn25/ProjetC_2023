#include "include/foret.h"
#include "include/cellules.h"
#include "include/grille.h"

struct foret buildForet(struct grille tab, struct cellule** ens) {
    struct foret f = {tab, ens};
    return f;
}

void afficheForet(struct foret f) {
    for (int i = 0; i < f.tab.l; i++) {
        for (int j = 0; j < f.tab.L; j++) {
            printf(" %c ", f.ensemble[i][j].type);
        }  
        printf("\n");
    }
}

void afficheEtatForet(struct foret f) {
    for (int i = 0; i < f.tab.l; i++) {
        for (int j = 0; j < f.tab.L; j++) {
            printf(" %d ", f.ensemble[i][j].etat);
        }  
        printf("\n");
    }
}

int setFeuCellule(struct foret f, int x, int y) {
    if( x < 0 || y < 0 || x >= f.tab.l || y >= f.tab.L) {
        printf("Coordonnée invalide\n");
        return 1;
    }
    f.ensemble[x][y].etat = 1;
    return 0;
}
