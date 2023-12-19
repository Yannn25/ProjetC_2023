#include "include/grille.h"

struct grille recupDim() {
    int l = 0;
    int L = 0;
    printf("Commencons par entrer les dimensions de la foret \n");
    printf("entrer la largeur : ");
    scanf("%d", &L);
    printf("entrer la longeur : ");
    scanf("%d", &l);
    printf("\nles dimensions de votre foret :%d %d\n", L, l);
    struct grille res = {l, L};
    return res;
}