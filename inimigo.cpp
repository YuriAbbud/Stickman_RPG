#include "inimigo.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#ifndef INIMIGO_H
#define INIMIGO_H

Inimigo::Inimigo(float mult) {
    int index = rand() % 3;

    string lista_nomes[] = {"Ladrao", "Zumbi", "Lobisomen"};
    int lista_vida[] = {5, 7, 9};
    int lista_dano[] = {3, 4, 5};

    Nome = lista_nomes[index];
    Vida = lista_vida[index] * mult;
    Dano = lista_dano[index] * mult;
}

void Inimigo::ReceberDano(int dano) {
    Vida -= dano;
    
    cout << '\n' << Nome << " recebeu " << dano << " de dano" << endl;
}

#endif