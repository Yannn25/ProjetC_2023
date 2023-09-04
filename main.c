#include <stdio.h>
#include <stdlib.h>
#include <time.h>   // pour rand
#include "include/cellules.h"
#include "include/grille.h"

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
int afficheType(int i, int j) {
    int r;
    printf("\nQuel type de cellule voulez vous a la case [ %d, %d ]:\n", i,j);
    printf("1.Sol\n2.Arbre\n3.Feuille\n4.Roche\n5.Herbre\n6.Eau\n7.Cendres\n8.Cendres Eteintes\n(Entrez le numéro)\n");
    scanf("%d", &r);
    return r;
}
struct cellule** initTabAlea(int l, int L) {
    srand(time(NULL));
    int nbgen; 
    struct cellule** res = (struct cellule**)malloc(l * sizeof(struct cellule*));
    for (int i = 0; i < l; i++) {
        res[i] = (struct cellule*)malloc(L * sizeof(struct cellule));
    }
    for(int i=0; i < l; i++) {
        for(int j=0; j < L; j++) {
            nbgen = rand() % 8 + 1;   
            printf("%d\n", nbgen);
            res[i][j] = CreerType(nbgen);
        }
    }
    return res;
}

struct cellule** initTabMan(int l, int L) {
    struct cellule** res = (struct cellule**)malloc(l * sizeof(struct cellule*));
    for (int i = 0; i < l; i++) {
        res[i] = (struct cellule*)malloc(L * sizeof(struct cellule));
    }
    for(int i=0; i < l; i++) {
        for(int j=0; j < L; j++) {
            res[i][j] = CreerType(afficheType(i+1,j+1));
        }
    }
    return res;
}
void afficheForet(struct cellule** foret, int l, int L) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < L; j++) {
            printf(" %c ", foret[i][j].type);
        }  
        printf("\n");
    }
}
int main() {
    
    struct grille tab = recupDim();
    
    struct cellule** foret =  initTabAlea(tab.l, tab.L);
    afficheForet(foret, tab.l, tab.L);
    
      
    return 0;
}