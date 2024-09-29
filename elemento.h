#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

#ifndef ELEMENTO
#define ELEMENTO

class Elemento {
    public:
        Elemento();
        bool tipo; // true = arma, false = poção

        string Nome;
        int Pontos;
        int Peso;
};

#endif