#include "heroi.h"

using namespace std;

Heroi::Heroi() {
    cout << "Digite o nome do Heroi: ";
    getline(cin, Nome);
    system("CLS");
    Vida_Base = 20;
    Vida_Max = Vida_Atual = Vida_Base;
    Dano_Base = 4;
    Level = 1;
    Mult = 1;
    EXP = 0;
}

void Heroi::LevelUp() {
    int expNecessaria;

    while (true) {
        expNecessaria = (150 * pow(Level, 1.5));

        if (EXP < expNecessaria) {
            return;
        }
        Level++;
        EXP = 0;
        Mult = 1 + (Level - 1) * 0.2; //20%

        cout << "Level Up! " << Nome << " agora esta no nivel " << Level << endl;
        cout << "MaxVida: "<< static_cast<int>(Vida_Max )<< " -> " << static_cast<int>(Vida_Base * Mult) << "\nDano base: " << static_cast<int>(Dano_Base) << " -> " << static_cast<int>(Dano_Base * Mult) << endl;

        Vida_Max = (Vida_Base * Mult);
        Vida_Atual = (Vida_Atual * Mult);
        Dano_Base = (Dano_Base * Mult);
    }
}

void Heroi::ReceberDano(int Dano) {
    Vida_Atual -= Dano;

    cout << Nome << " recebeu " << Dano << " de dano" << endl;
}

void Heroi::Curar(int Cura) {
    Vida_Atual += Cura;

    if (Vida_Atual > Vida_Max) {
        Vida_Atual = Vida_Max;
    }
    
    cout << Nome << " curou-se " << Cura << " pontos de vida\nVida atual: " << Vida_Atual << endl;
}