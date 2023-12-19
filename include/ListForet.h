#ifndef LISTFORET_H
#define LISTFORET_H

#include <stdio.h>
#include <stdlib.h>
#include "foret.h"
#include "cell.h"
#include "foret.h"

typedef struct ListForet {
    struct Cell * head;
} ListForet;

struct ListForet * ListForetVide();
int EstVideListForet(const struct ListForet * l);
int lenList(struct ListForet * l);
void FirstAdd(struct ListForet *l, struct foret * ajt);
void addEnTete(struct ListForet *l, struct foret * ajt);
struct foret * getHead(struct ListForet * l);
struct Cell * getAt(struct ListForet * l, int pos);
void libererList(struct ListForet * l);
void setAt(struct ListForet * l, int pos);
#endif