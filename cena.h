#include <iostream>
#include <fstream>
#include <unistd.h>

#ifndef CENA
#define CENA

#include "dynamic_stack.h"
#include "queue.h"
#include "heroi.h"
#include "inventario.h"
#include "sqm.h"

void EndGame(Heroi &Player, int seed);

void GerarMapa(Heroi &Player, Stack &Mochila, List &Cinto, int seed); 

void Intro();

void Venceu(Heroi &Player, int seed);

#endif