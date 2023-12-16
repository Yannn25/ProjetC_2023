#include "include/cellules.h"
#include <stdlib.h>
#include <time.h> // pour rand

int afficheType(int i, int j) {
    int r;
    printf("\nQuel type de cellule voulez vous a la case [ %d, %d ]:\n", i, j);
    printf("1.Sol\n2.Arbre\n3.Feuille\n4.Roche\n5.Herbre\n6.Eau\n7.Cendres\n8.Cendres Eteintes\n(Entrez le numéro)\n");
    scanf("%d", &r);
    return r;
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

struct cellule **TabAlea(int l, int L) {
    srand(time(NULL));
    int nbgen;
    struct cellule **res = (struct cellule **)malloc(l * sizeof(struct cellule *));
    for (int i = 0; i < l; i++)
    {
        res[i] = (struct cellule *)malloc(L * sizeof(struct cellule));
    }
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < L; j++)
        {
            nbgen = rand() % 8 + 1;
            res[i][j] = CreerType(nbgen);
        }
    }
    return res;
}

struct cellule **TabMan(int l, int L) {
    struct cellule **res = (struct cellule **)malloc(l * sizeof(struct cellule *));
    for (int i = 0; i < l; i++)
    {
        res[i] = (struct cellule *)malloc(L * sizeof(struct cellule));
    }
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < L; j++)
        {
            res[i][j] = CreerType(afficheType(i + 1, j + 1));
        }
    }
    return res;
}
struct cellule **initTab(int l, int L) {
    int choix = 0;
    printf("Comment souhaitez vous remplir la foret ((0) Aléatoirement, (1) Manuellement)\n");
    scanf("%d", &choix);
    if(choix == 1)
        return TabMan(l, L);
    else
        return TabAlea(l,L);
}


void toString(struct cellule cel) {
    printf("Type -> %c Degre -> %d Etat -> %d", cel.type, cel.degre, cel.etat);
}

void setType(struct cellule *cel, char t) {
    cel->type = t;
}
void setDegre(struct cellule *cel, int d) {
    cel->degre = d;
}
void setEtat(struct cellule *cel, int e) {
    cel->etat = e;
}

int estTypeSpe(char c) {
    if(c == ' ' || c == '*' || c == '#' || c == 'x' )
        return 1;
    else
        return 0;
}

int estEnFeu(struct cellule *cel) {
    return (cel->etat == 1) ? 1 : 0;
}