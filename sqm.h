#include <iostream>

#ifndef SQM
#define SQM

#include "dynamic_stack.h"
#include "queue.h"
#include "inimigo.h"
#include "heroi.h"
#include "inventario.h"
#include "cena.h"

void SQM_Batalha(Heroi &Player, Stack &Mochila, List &Cinto, int seed);

void SQM_Item(Heroi &Player, Stack &Mochila, List &Cinto);

void SQM_Vazio(Heroi &Player, Stack &Mochila, List &Cinto);

#endif