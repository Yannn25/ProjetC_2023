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

int modifCellule(struct foret f, int x, int y) {
    if( x < 0 || y < 0 || x >= f.tab.l || y >= f.tab.L) {
        printf("Coordonnée invalide\n");
        return 1;
    }
    printf("Voici votre cellule actuel : ");
    toString(f.ensemble[x][y]);
    printf("\nQue souhaitez vous modifiez ? (t) pour le type, (d) pour le degre (e) pour l'etat : ");
    char c;
    int a;
    scanf(" %c", &c);
    switch (c) {
        case 't':
            printf("Entrer le nouveau type de la cellule (+*/- ): ");
            scanf(" %c", &c);
            setType(&f.ensemble[x][y], c);
            break;
        case 'd':
            printf("Entrer le nouveau degre de la cellule (<6): ");
            scanf(" %d", &a);
            printf("\n %d", a);
            setDegre(&f.ensemble[x][y], a);
            break;
        case 'e':
            printf("Entrer le nouveau etat de la cellule (0) ou (1): ");
            scanf(" %d", &a);
            printf("\n %d", a);
            setEtat(&f.ensemble[x][y], a);
            break;
        default :
            return 0;
    }
    printf("Voici votre nouvelle cellule  : ");
    toString(f.ensemble[x][y]);
    return 0;
}
