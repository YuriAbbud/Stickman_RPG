#include "cena.h"

void Intro() {
    int delay = 2000000;// 1000000 (1sec)
    int fastDelay = 7000;
    ifstream intro("textos/intro.txt");
    string linha;
    if (!intro) {
        cerr << "Nao foi possivel abrir o arquivo intro.txt" << endl;
        exit(0);
    }
    while (getline(intro, linha)) {
        cout << linha << endl;
    }
    intro.close();

    PressEnter();

    ifstream welcome("textos/welcome.txt");
    if (!welcome) {
        cerr << "Nao foi possivel abrir o arquivo welcome.txt" << endl;
        exit(0);
    }
    while (getline(welcome, linha)) {
        cout << linha << endl;
        usleep(delay);
    }
    welcome.close();
    
    PressEnter();
    system("CLS");
    
    ifstream inicio("textos/inicio.txt");
    if (!inicio) {
        cerr << "Nao foi possivel abrir o arquivo inicio.txt" << endl;
        exit(0);
    }

    char c;
    while (inicio.get(c)) {
        if (c == '\n') {
            cout << c;
        } else {
            cout << c;
            usleep(fastDelay);
        }
    }
    inicio.close();

    cout << '\n';
    PressEnter();
    system("CLS");
}

void EndGame(Heroi &Player, int seed) {
    system("CLS");
    cout << "Fim de jogo!\nVerifique seu placar no arquivo high_scores.txt" << endl;
    fstream log("high_scores.txt", ios::app | ios::out);
    if (log) {
        log << "Seed: " << seed << endl;
        log << "Nome: " << Player.Nome << endl;
        log << "Level: " << Player.Level << endl << endl;
        log.close();
    } else {
        cout << "Nao foi possivel abrir high_scores.txt" << endl;
    }
    exit(0);
}

void GerarMapa(Heroi &Player, Stack &Mochila, List &Cinto, int seed) {
    if (Player.Level != 10) {
        int index = rand() % 3;

        switch (index) {
        case 0:
            SQM_Item(Player, Mochila, Cinto);
            break;
        case 1:
            SQM_Batalha(Player, Mochila, Cinto, seed);
            break;
        case 2:
            SQM_Vazio(Player, Mochila, Cinto);
            break;
        }
    } else {
        Venceu(Player, seed);
    }
}

void Venceu (Heroi &Player, int seed) {
    int fastDelay = 7000;
    ifstream inicio("textos/venceu.txt");
    if (!inicio) {
        cerr << "Nao foi possivel abrir o arquivo inicio.txt" << endl;
        exit(0);
    }

    char c;
    while (inicio.get(c)) {
        if (c == '\n') {
            cout << c;
        } else {
            cout << c;
            usleep(fastDelay);
        }
    }
    inicio.close();

    PressEnter();
    system("CLS");

    cout << "Parabens " << Player.Nome << " hora de descansar...\n" << endl << endl;

cout << "          ___   ____\n"
            "        /' --;^/ ,-_\\     \\ | /\n"
            "       / / --o\\ o-\\ \\\\   --(_)--\n"
            "      /-/-/|o|-|\\-\\\\|\\\\   / | \\\n"
            "       '`  ` |-|   `` '\n"
            "             |-| \n"
            "             |-|O\n"
            "             |-(\\,__\n"
            "          ...|-|\\--,\\_....\n"
            "      ,;;;;;;;;;;;;;;;;;;;;;;;;,.\n"
            "~~,;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
            "~;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,  ______   ---------   _____     ------\n\n";

    PressEnter();
    EndGame(Player, seed);
}