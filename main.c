#include <stdio.h>
#include <stdlib.h>
#include "include/cellules.h"
#include "include/grille.h"

void afficheSymbole(struct cellule foret) {
    switch (foret.type) {
        case 'S':
            printf(" + ");
            break;
        case 'A':
            printf(" * ");
            break;
        case 'F':
            printf("   ");
            break;
        case 'R':
            printf(" # ");
            break;
        case 'H':
            printf(" x ");
            break;
        case 'E':
            printf(" / ");
            break;
        case 'C':
            printf(" - ");
            break;
        case 'Z':
            printf(" @ ");
            break;
        default:
            break;
    }

}

struct grille recupDim() {
    int l = 0;
    int L = 0;
    printf("entrer les dimensions de a la foret :\n");
    printf("entrer largeur :\n");
    scanf("%d", &l);
    printf("entrer largeur :\n");
    scanf("%d", &L);
    printf("les dimensions de votre foret :%d %d\n", l,L);
    struct grille res = {l,L};
    return res;
}

struct cellule** initTab(int l, int L) {
    struct cellule** res = (struct cellule**)malloc(l * sizeof(struct cellule*));
    struct cellule var = {'S', 0, 0};
    for (int i = 0; i < l; i++) {
        res[i] = (struct cellule*)malloc(L * sizeof(struct cellule));
    }
    for(int i=0; i < l; i++) {
        for(int j=0; j < L; j++) {
            res[i][j] = var;
        }
    }
    return res;
}
void afficheForet(struct cellule** foret, int l, int L) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; i < L; i++) {
           // afficheSymbole(foret[i][j]);
        }
    }
    
}
int main() {
    
    struct grille tab = recupDim();
    
    struct cellule** foret =  initTab(tab.l, tab.L);
    afficheForet(foret, tab.l, tab.L);
    
      
    return 0;
}