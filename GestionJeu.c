#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/GestionJeu.h"
#include "include/color_terminal.h"
#include "include/cellules.h"
#include "include/grille.h"
#include "include/foret.h"
#include "include/ListForet.h"

int askIterations() {
    printf("Combien d'itérations souhaitez vous réaliser ?\n");
    int ret = 0;
    scanf("%d", &ret);
    return ret;
}

void Simulation(int lim, struct foret * f) {
    printf("\n");
    char rep;
    int a, b, c, d, iter = 0;
    ListForet * list = ListForetVide();
    FirstAdd(list, f);
    while (lim > 0) {
        printf("\nItération %d\n", iter++);
        afficheForet(f);
        printf("\n Entré (c) pour continuer (q) pour quitter\nTaper (f) pour mettre une case en feu \n(m) pour modifier une case \n(r) pour revenir en arrière\n(v) pour vérifié la possibilité d'une propagation \n");
        scanf(" %c", &rep);
        switch (rep) {
            case 'f':
                printf("Entrer les coordonnéesde la case a mettre en feu avec un espace : ");
                if (scanf("%d %d", &a, &b) != 2) {
                    printf("Les coordonées entrer ne sont pas correctes...\n");
                    iter--;
                    continue;
                }
                iter += setFeuCellule(f, a, b);
                printf("\n");
                break;
            case 'm':
                printf("Entrer les coordonnées de la case a modifier avec un espace : ");
                if (scanf("%d %d", &a, &b) != 2) {
                    printf("Les coordonées entrer ne sont pas correctes...\n");
                    iter--;
                    continue;
                }
                iter += modifCellule(f, a, b);
                printf("\n");
                break;
            case 'r':
                printf("Vous avez la possibilité de retourner jusqu'à %d étapes\nDe combien d'étapes souhaiter vous retourner en arrières : ", lenList(list)-1);
                if(scanf("%d", &a) != 1 || a < 0) {
                    printf("Veuillez saisir un nombre entier positif.\n");
                    iter--;
                    continue;
                }
                if(a >= lenList(list)) {
                    printf("Vous ne pouvez pas réculer d'autant d'étapes\n");
                    iter--;
                    continue;
                }
                setAt(list, a);
                printf("Retour en arrière de %d étapes effectué avec succès.\n", a);
                f = list->head->cellForet;
                continue;
            case 'c':
                if(lim == 1) {
                    printf("Fin de la partie ! \nVoici l'état final de votre foret\n");
                    afficheForet(f);
                    libererForet(f);
                    libererList(list);
                    return;
                }
                addEnTete(list, copieForet(f));
                f = propagation(f);
                lim--;
                break;
            case 'v' :
                printf("Entrer les coordonnées de la case A avec un espace : ");
                if (scanf("%d %d", &a, &b) != 2) {
                    printf("Les coordonées entrer ne sont pas correctes...\n");
                    iter--;
                    continue;
                }
                printf("Entrer les coordonnées de la case B avec un espace : ");
                if (scanf("%d %d", &c, &d) != 2) {
                    printf("Les coordonées entrer ne sont pas correctes...\n");
                    iter--;
                    continue;
                }
                int * rep = verifPropagation(f, a, b, c, d);
                if(rep[0])
                    printf("Le chemin menant de A à B est de %d et nécessites %d étapes de propagation\n", rep[0], rep[1]);
                else 
                    printf("La propagation de A à B n'est pas possible\n");
                break;
            case 'q':
                printf("Fin de la partie\n");
                return;
            default:
                printf("Votre entrée n'est pas compris\n");
                iter--;
                break;
        }
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