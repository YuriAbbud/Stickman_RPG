#include "inventario.h"

void PressEnter() {
    cout << "\nPressione \"Enter\" para continuar" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void MostrarItem(Elemento &Temp) {
    if (Temp.tipo) {
        cout << Temp.Nome << " | Dano: " << Temp.Pontos << " | Peso: " << Temp.Peso << endl;
    } else {
        cout << Temp.Nome << " | Cura: " << Temp.Pontos << " | Peso: " << Temp.Peso << endl;
    }
}

void MostrarCinto(List &Cinto) {
    Elemento Temp;
    cout << "\n-=-=-=- CINTO -=-=-=-" << endl;
    for (int i = 1; i <= 3; i++) {
        if (i <= Cinto.Size()) {
            Cinto.Retrieve(i, Temp);
            cout << i << " - ";
            MostrarItem(Temp);
        } else {
            cout << i << " - vazio" << endl;
        }
    }
}

void MostrarMochila(Stack &Mochila) {
    Elemento Temp;
    cout << "\n-=-=-=- MOCHILA -=-=-=-\nItem do topo: ";
    if (Mochila.Empty()) {
        cout << "- vazio -" << endl;
    } else {
        Mochila.Top(Temp);
        MostrarItem(Temp);
        cout << "E outros " << Mochila.Size() - 1 << " itens" << endl;
    }
}

bool CintoTemArma(List &Cinto) {
    Elemento Temp;
    for (int i = 1; i <= Cinto.Size(); i++) {
        Cinto.Retrieve(i, Temp);
        if (Temp.tipo) {
            return true;
        }
    }
    return false;
}

bool MochilaTemArma(Stack &Mochila) {
    Elemento Temp;
    Stack TempStack;
    bool temArma = false;

    while (!Mochila.Empty()) {
        Mochila.Pop(Temp);
        TempStack.Push(Temp);
    }

    while (!TempStack.Empty()) {
        TempStack.Pop(Temp);
        if (Temp.tipo) {
            temArma = true;
        }
        Mochila.Push(Temp);
    }

    return temArma;
}