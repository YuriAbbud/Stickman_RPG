#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

#ifndef INIMIGO
#define INIMIGO

class Inimigo {
    public:
        Inimigo(float mult);
        //Não precisa de ~Inimigo();
        void ReceberDano(int dano);
        
        string Nome;
        int Vida, Dano;
};

#endif