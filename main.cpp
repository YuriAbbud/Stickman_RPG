/*
Yuri Ravagnani Abbud - 2210568
g++ main.cpp cena.cpp dynamic_stack.cpp elemento.cpp heroi.cpp inimigo.cpp inventario.cpp queue.cpp sqm.cpp -o jogo.exe

Gostei muito de fazer esse trabalho, infelizmente não tive força de vontade para tratar de todos os erros do cin que o usuario pode usar, mas se seguir exatamente o que o jogo pede, da certo.

Não sei se usei o #ifndef #define corretamente e de maneira eficiente, usei um vídeo do YouTube explicando sobre quando e como usar, mas nenhum se encaixou no caso em que temos a class no .h e a implementação no .cpp : https://www.youtube.com/watch?v=RU5JUHAiR18

https://github.com/YuriAbbud/Stickman_RPG

Pretendo aprimorar o jogo (ou criar outro) para aprender mais sobre SFML e me divertir com isso.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "heroi.h"
#include "dynamic_stack.h"
#include "queue.h"
#include "sqm.h"

using namespace std;

int main() {
    int seed = time(0);
    srand(seed);

    Heroi Player;
    Stack Mochila;
    List Cinto;

    Intro();

    while (true) {
        GerarMapa(Player, Mochila, Cinto, seed);
        system("CLS");
    }

    return 0;
}