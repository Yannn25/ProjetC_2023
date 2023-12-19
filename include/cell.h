#ifndef CELL_H
#define CELL_H

#include "foret.h" 

typedef struct Cell {
    struct foret *cellForet;
    struct Cell *prec;
} Cell;

struct Cell * createCell(struct foret * f);
void libererCell(struct Cell * c);

#endif 
