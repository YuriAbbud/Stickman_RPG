#include <iostream>
#include <limits>

#ifndef INVENTARIO
#define INVENTARIO

#include "elemento.h"
#include "dynamic_stack.h"
#include "queue.h"

void PressEnter();

void MostrarItem(Elemento &Temp);

void MostrarCinto(List &Cinto);

void MostrarMochila(Stack &Mochila);

bool CintoTemArma(List &Cinto);

bool MochilaTemArma(Stack &Mochila);

#endif