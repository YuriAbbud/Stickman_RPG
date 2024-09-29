#include <string>
using namespace std;

class Heroi {
    public:
        Heroi();
        void LevelUp();
        void ReceberDano(int Dano);
        void Curar(int Cura);

        int EXP;
        float Mult;
        string Nome;
        int Vida_Base, Vida_Max, Vida_Atual, Dano_Base, Level;
        //Cinto
        //Mochila
};
