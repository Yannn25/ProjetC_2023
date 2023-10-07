#ifndef FORET_H
#define FORET_H

#include <stdio.h>
#include "cellules.h"
#include "grille.h"

typedef struct foret {
    struct grille tab;
    struct cellule**  ensemble;
} foret;

struct foret buildForet(struct grille grid, struct cellule** ens);
void afficheForet(struct foret f);

#endif 