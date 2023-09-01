#include "include/cellules.h"


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