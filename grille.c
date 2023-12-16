#include "include/grille.h"

struct grille recupDim() {
    int l = 0;
    int L = 0;
    printf("entrer les dimensions de a la foret :\n");
    printf("entrer la largeur :\n");
    scanf("%d", &L);
    printf("entrer la longeur :\n");
    scanf("%d", &l);
    printf("les dimensions de votre foret :%d %d\n", l, L);
    struct grille res = {l, L};
    return res;
}