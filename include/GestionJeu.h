#ifndef GESTIONJEU_H
#define GESTIONJEU_H

#include "foret.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color_terminal.h"
#include "cellules.h"
#include "grille.h"
#include "foret.h"
#include "ListForet.h"
#include "ArbreForet.h"
#include "Noeud.h"

int askIterations();
void Simulation(int lim, struct foret * f);
void play();

#endif 