#include <cstdlib>
#include <iostream>
#include <string>

#include "elemento.h"

using namespace std;

Elemento::Elemento() {
    tipo = rand() % 2; //defini do tipo (arma/poção)
    int index = rand() % 3;

    string arma_nome[] = {"Machado", "Espada", "Arco"};
    int arma_dano[] = {5, 4, 3};
    int arma_peso[] = {10, 8, 4};

    string pocao_nome[] = {"Pocao Pequena", "Pocao Media", "Pocao Grande"};
    int pocao_cura[] = {5, 8, 12};
    int pocao_peso[] = {2, 4, 6};

    if (tipo) {
        Nome = arma_nome[index];
        Pontos = arma_dano[index];
        Peso = arma_peso[index];
    } else {
        Nome = pocao_nome[index];
        Pontos = pocao_cura[index];
        Peso = pocao_peso[index];
    }
    
}

Elemento::~Elemento() {
    //Caso eu for fazer dinâmicamente
}