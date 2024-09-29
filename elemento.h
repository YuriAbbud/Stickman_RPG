#include <string>

using namespace std;

#ifndef ELEMENTO_H
#define ELEMENTO_H

class Elemento {
    public:
        Elemento();
        ~Elemento();
        bool tipo; // true = arma, false = poção

        string Nome;
        int Pontos;
        int Peso;
};

#endif