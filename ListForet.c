#include "include/ListForet.h"


struct ListForet * ListForetVide(){
    struct ListForet * ret = (struct ListForet *)malloc(sizeof(struct ListForet));
    if(ret == NULL){
        perror("erreur sur malloc....(-_-)\n");
    }
    ret->head = NULL;
    return ret;
}

int EstVideListForet(const struct ListForet * l) {
    return l->head == NULL;
}

int lenList( struct ListForet * l) {
    if(EstVideListForet(l)) return 0;
    Cell * courant = l->head;
    int cpt = 0;
    while(courant != NULL) {
        cpt++;
        courant = courant->prec;
    }
    return cpt;
}

void FirstAdd(struct ListForet * l, struct foret * ajt) {
    if(!EstVideListForet(l)) return;
    l->head = createCell(ajt);
}

void  addEnTete(struct ListForet *l, struct foret * ajt) {
    if(EstVideListForet(l))
        FirstAdd(l, ajt);
    Cell * newhead = createCell(ajt);
    newhead->prec = l->head;
    l->head = newhead;
}

struct foret * getHead(struct ListForet * l) {
    return l->head->cellForet;
}

struct Cell * getAt(struct ListForet * l, int pos) {
    if(EstVideListForet(l) || pos > lenList(l)) return NULL;
    int incr = pos;
    Cell * courant = l->head;
    while(incr != 0) {
        incr--;
        courant = courant->prec;
    }
    return courant;
}

void libererList(struct ListForet * l) {
   while(!EstVideListForet(l)) {
        Cell * tmp = l->head;
        l->head = l->head->prec;
        free(tmp);
   }
}

void setAt(struct ListForet * l, int pos) {
    if(EstVideListForet(l) || pos > lenList(l)) return;
    int incr = pos;
    Cell * tmp = l->head;
    while(incr != 0) {
        incr--;
        Cell * aLiberer = tmp;
        tmp = tmp->prec;
        libererCell(aLiberer);
    }
    l->head = tmp;
}