#include <string>

using namespace std;

class Inimigo {
    public:
        Inimigo(float mult);
        //Não precisa de ~Inimigo();
        void ReceberDano(int dano);
        
        string Nome;
        int Vida, Dano;
};