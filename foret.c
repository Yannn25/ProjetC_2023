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

struct cellule CreerType(int rep) {
    struct cellule var= {'+', 0, 0};
    switch (rep) {
        case 1:
            break;
        case 2:
            var.type = '*';
            var.degre = 4; 
            break;
        case 3:
            var.type = ' ', 
            var.degre = 2; 
            break;
        case 4:
            var.type = '#';
            var.degre = 5;
            break;
        case 5:
            var.type = 'x', 
            var.degre = 3;
            break;
        case 6 :
            var.type = '/'; 
            break;
        case 7:
            var.type = '-'; 
            var.degre = 1;
            break;
        case 8 :
            var.type = '@'; 
            break;
    }
    return var;
}