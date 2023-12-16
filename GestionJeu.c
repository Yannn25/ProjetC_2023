#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/GestionJeu.h"
#include "include/color_terminal.h"
#include "include/cellules.h"
#include "include/grille.h"
#include "include/foret.h"

int askIterations() {
    printf("Combien de d'itérations souhaitez vous réaliser ?\n");
    int ret = 0;
    scanf("%d", &ret);
    return ret;
}

void Simulation(int lim, struct foret * f) {
    printf("\n");
    char rep;
    int a, b;
    while (lim > 0) {
        afficheForet(f);
        printf("\n Appuyer sur (c) pour continuer, taper (f) pour mettre une case en feu, taper (m) pour modifier une case : \n");
        scanf(" %c", &rep);
        //printf("%c", rep);
        switch (rep) {
        case 'f':
            printf("Entrer vos coordonnées avec un espace : ");
            if (scanf("%d %d", &a, &b) != 2)
            {
                printf("Invalid input for coordinates.");
                return;
            }
            printf("%d %d\n", a, b);
            lim += setFeuCellule(f, a, b);
            afficheEtatForet(f);
            printf("\n");
            break;
        case 'm':
            printf("Entrer les coordonnées de la case a modifier avec un espace : ");
            if (scanf("%d %d", &a, &b) != 2)
            {
                printf("Invalid input for coordinates.");
                return;
            }
            printf("%d %d\n", a, b);
            lim += modifCellule(f, a, b);
            printf("\n");
            break;
        case 'c':
            if(lim == 1) {
                printf("Fin de la partie ! \n Voici l'état final de votre foret\n");
                afficheEtatForet(f);
                libererForet(f);
                return;
            }
            break;;
        default:
            printf("Invalid input for coordinates.");
            lim++;
            break;
        }
        f = propagation(f);
        lim--;
    }

}

void play() {
    struct grille tab = recupDim();
    struct cellule **ensembles = initTab(tab.l, tab.L);
    struct foret * foret = buildForet(tab, ensembles);
    //afficheForet(foret);
    int nbIterarions = askIterations();
    Simulation(nbIterarions, foret);
}