#include "include/cell.h"

struct Cell * createCell(struct foret * f) {
    Cell * c = malloc(sizeof(Cell));
    if (c == NULL)
        perror("erreur sur malloc...\n");
    c->cellForet = f;
    c->prec = NULL;
    return c;
}

void libererCell(struct Cell * c){
    libererForet(c->cellForet);
    free(c);
}