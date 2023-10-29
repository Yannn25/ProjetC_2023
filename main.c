#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // pour rand
#include "include/cellules.h"
#include "include/grille.h"
#include "include/foret.h"

struct grille recupDim()
{
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
int afficheType(int i, int j)
{
    int r;
    printf("\nQuel type de cellule voulez vous a la case [ %d, %d ]:\n", i, j);
    printf("1.Sol\n2.Arbre\n3.Feuille\n4.Roche\n5.Herbre\n6.Eau\n7.Cendres\n8.Cendres Eteintes\n(Entrez le numéro)\n");
    scanf("%d", &r);
    return r;
}
struct cellule **initTabAlea(int l, int L)
{
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

struct cellule **initTabMan(int l, int L)
{
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

int askIterations()
{
    printf("Combien de d'itérations souhaitez vous réaliser ?\n");
    int ret = 0;
    scanf("%d", &ret);
    return ret;
}

void Tour(int lim, struct foret f)
{
    printf("\n");
    char rep;
    int a, b;
    while (lim > 0)
    {
        afficheForet(f);
        printf("\n Appuyer sur entrée ou taper f pour mettre une case en feu : \n");
        scanf(" %c", &rep);
        printf("%c", rep);
        if (rep == 'f')
        {
            printf("Entrer vos coordonnées avec un espace : ");
            if (scanf("%d %d", &a, &b) != 2)
            {
                printf("Invalid input for coordinates.");
                return;
            }
            printf("%d %d", a, b);
        }
        while (getchar() != '\n');
        lim--;
    }
}

int main()
{

    struct grille tab = recupDim();

    struct cellule **ensembles = initTabAlea(tab.l, tab.L);
    struct foret foret = buildForet(tab, ensembles);
    afficheForet(foret);
    int nbIterarions = askIterations();
    Tour(nbIterarions, foret);
    return 0;
}