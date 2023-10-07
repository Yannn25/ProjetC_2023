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