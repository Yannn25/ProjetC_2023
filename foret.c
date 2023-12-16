#include "include/foret.h"


struct foret * buildForet(struct grille tab, struct cellule** ens) {
    struct foret *f = (struct foret *)malloc(sizeof(struct foret));
    if(f == NULL) {
        perror("erreur sur malloc....(-_-)\n");
    }
    f->tab = tab;
    f->ensemble = ens;
    return f;
}

void afficheForet(const struct foret * f) {
    for (int i = 0; i < f->tab.l; i++) {
        for (int j = 0; j < f->tab.L; j++) {
            printf(" %c ", f->ensemble[i][j].type);
        }  
        printf("\n");
    }
}

void afficheEtatForet(const struct foret * f) {
    for (int i = 0; i < f->tab.l; i++) {
        for (int j = 0; j < f->tab.L; j++) {
            printf(" %d ", f->ensemble[i][j].etat);
        }  
        printf("\n");
    }
}

int setFeuCellule(struct foret * f, int x, int y) {
    if( x < 0 || y < 0 || x >= f->tab.l || y >= f->tab.L) {
        printf("Coordonnée invalide\n");
        return 1;
    }
    f->ensemble[x][y].etat = 1;
    return 0;
}

int modifCellule(struct foret * f, int x, int y) {
    if( x < 0 || y < 0 || x >= f->tab.l || y >= f->tab.L) {
        printf("Coordonnée invalide\n");
        return 1;
    }
    printf("Voici votre cellule actuel : ");
    toString(f->ensemble[x][y]);
    printf("\nQue souhaitez vous modifiez ? (t) pour le type, (d) pour le degre (e) pour l'etat : ");
    char c;
    int a;
    scanf(" %c", &c);
    switch (c) {
        case 't':
            printf("Entrer le nouveau type de la cellule (+*/- ): ");
            scanf(" %c", &c);
            setType(&f->ensemble[x][y], c);
            break;
        case 'd':
            printf("Entrer le nouveau degre de la cellule (<6): ");
            scanf(" %d", &a);
            printf("\n %d", a);
            setDegre(&f->ensemble[x][y], a);
            break;
        case 'e':
            printf("Entrer le nouveau etat de la cellule (0) ou (1): ");
            scanf(" %d", &a);
            printf("\n %d", a);
            setEtat(&f->ensemble[x][y], a);
            break;
        default :
            return 0;
    }
    printf("Voici votre nouvelle cellule  : ");
    toString(f->ensemble[x][y]);
    return 0;
}


struct foret * copieForet(const struct foret *f) {
    struct foret * copie = (struct foret *)malloc(sizeof(struct foret));
    copie->tab = f->tab;
    copie->ensemble = malloc(f->tab.l * sizeof(cellule*));
    for (int i = 0; i < f->tab.l; i++) {
        copie->ensemble[i] = malloc(f->tab.L * sizeof(cellule));
        for(int j = 0; j < f->tab.L; j++) {
            copie->ensemble[i][j] = f->ensemble[i][j];
        }
    }
    return copie;
}

//Fonction pour libérer la mémoire allouée pour une structure foret
void libererForet(struct foret* f) {
    for (int i = 0; i < f->tab.l; ++i) {
        free(f->ensemble[i]);
    }
    free(f->ensemble);
}

int verifVoisins(int i, int j, struct foret * f) {
    //Liste des positions possibles pour nos voisins
    int voisins[8][2] = {
        {-1,-1},{-1,0},{-1,1},
        {0,-1}, {0,1},
        {1,-1},{1,0},{1,1}
    };
    for(int z = 0; z < 8; ++z) {
        int vi = i + voisins[z][0];
        int vj = j + voisins[z][1];
        //Vérif des cas limites de notre tableau
        if(vi >= 0 && vi < f->tab.l && vj >= 0 && vj < f->tab.L) {
            if(estEnFeu(&f->ensemble[vi][vj]))
                return 1;
        }
    }
    return 0;
}

struct foret * propagation(struct foret * f) {
    struct foret * copF = copieForet(f);
    printf("-- Avant propagation --\nEtat de f(original) :\n");
    afficheEtatForet(f);
    printf("\nEtat de la copie :\n");
    afficheEtatForet(copF);
    for(int i = 0; i < f->tab.l; i++) {
        for(int j = 0; j < f->tab.L; j++) {
            if(f->ensemble[i][j].type == '/' || f->ensemble[i][j].type =='+')
                continue;
            if(f->ensemble[i][j].degre > 2 && f->ensemble[i][j].etat == 1)
                copF->ensemble[i][j].degre -= 1;
            if(f->ensemble[i][j].degre == 2 && f->ensemble[i][j].etat == 1)
                copF->ensemble[i][j].type = '-';
            if(f->ensemble[i][j].type == '-')
                copF->ensemble[i][j].type = '@';
            if(estTypeSpe(f->ensemble[i][j].type) && verifVoisins(i,j,f)){
                copF->ensemble[i][j].degre -= 1;
                copF->ensemble[i][j].etat = 1;
            }
        }  
    }
    printf("-- Apres propagation --\nEtat de f(original) :\n");
    afficheEtatForet(f);
    printf("\nEtat de la copie :\n");
    afficheEtatForet(copF);
    libererForet(f);//si besoin de revenir en arriere peut etre intéresant de garder ca !
    return copF;
}