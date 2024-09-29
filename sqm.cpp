#include "sqm.h"

void SQM_Batalha(Heroi &Player, Stack &Mochila, List &Cinto, int seed) {
    Inimigo Inimigo(Player.Mult);
    Elemento Temp;
    char action;
    int pos;
    bool start = false;    

    while (Player.Vida_Atual > 0  && Inimigo.Vida > 0) {
        cout << "Nome: " << Player.Nome << "    HP: " << Player.Vida_Atual << '/' << Player.Vida_Max << endl; 
        MostrarCinto(Cinto);
        MostrarMochila(Mochila);
        cout << "\n+----------Sala da Luta----------+" << endl;
        cout << "Inimigo: " << Inimigo.Nome << "    HP: " << Inimigo.Vida << endl;

        if (!start) {
            cout << Player.Nome << " encontrou um " << Inimigo.Nome << " selvagem. Hora da batalha!" << endl;
            start = true;
        }
            escolhaMochilaCinto:
            cout << "\nUsar mochila ou cinto?\n(m - mochila | c - cinto | s - soco)\nDigite sua escolha: ";
            cin >> action;

            if ((Mochila.Empty() && Cinto.Empty()) && (action != 's' || action != 'S')) {
                cout << '\n' << Player.Nome << " nao possui itens, bora pra porrada" << endl;
                action = 's';
            } else if (Mochila.Empty() && (action == 'm' || action == 'M')) {
                cout << "\nMochila vazia, vamos recorrer ao cinto" << endl;
                action = 'c';
            } else if (Cinto.Empty() && (action == 'c' || action == 'C')) {
                cout << "\nCinto vazio, vamos recorrer a mochila" << endl;
                action = 'm';
            }

            switch (action) {
            case 's':
            case 'S':
                Inimigo.ReceberDano(Player.Dano_Base);
                if (Inimigo.Vida > 0) {
                    Player.ReceberDano(Inimigo.Dano);
                }
                break;
            case 'm':
            case 'M':
                Mochila.Top(Temp);
                cout << "\nQuer usar ";
                MostrarItem(Temp);
                cout << "(s - sim | n - nao | d - descartar)\nDigite sua escolha: ";
                cin >> action;
                switch (action) {
                case 's':
                case 'S':
                    if (Temp.tipo) {
                        Inimigo.ReceberDano(Player.Dano_Base + Temp.Pontos);
                        if (Inimigo.Vida <= 0) {
                            break;
                        }
                        Player.ReceberDano(Inimigo.Dano);
                    } else {
                        Player.Curar(Temp.Pontos);
                        Player.ReceberDano(Inimigo.Dano);
                    }
                    break;
                case 'n':
                case 'N':
                    goto escolhaMochilaCinto;
                    break;
                case 'd':
                case 'D':
                    Mochila.Pop(Temp);
                    cout << Player.Nome << " descartou ";
                    MostrarItem(Temp);
                    break;
                default:
                    cout << "Escolha invalida, tente novamente";
                    goto escolhaMochilaCinto;
                    break;
                }
                break;
            case 'c':
            case 'C':
                cout << "\nQual item do cinto quer usar?\nDigite sua escolha: ";
                cin >> pos;
                Cinto.Retrieve(pos, Temp);
                if (Temp.tipo) {
                    Inimigo.ReceberDano(Player.Dano_Base + Temp.Pontos);
                    if (Inimigo.Vida <= 0) {
                        break;
                    }
                    Player.ReceberDano(Inimigo.Dano);
                } else {
                    Player.Curar(Temp.Pontos);
                    Player.ReceberDano(Inimigo.Dano);
                }
                break;
            default:
                cout << "Escolha invalida, tente novamente";
                goto escolhaMochilaCinto;
                break;

        }
    PressEnter();
    system("CLS");
    }
    
    cout << "Nome: " << Player.Nome << "    HP: " << Player.Vida_Atual << '/' << Player.Vida_Max << endl; 
    MostrarCinto(Cinto);
    MostrarMochila(Mochila);
    cout << "\n+----------Sala da Luta----------+" << endl;

    if (Player.Vida_Atual <= 0) {
        cout << Inimigo.Nome << " derrotou " << Player.Nome << endl;
        EndGame(Player, seed);
    }

    if (Inimigo.Vida <= 0) {
        cout << Player.Nome << " derrotou " << Inimigo.Nome << endl;
    }

    cout << '\n' << Player.Nome << " recebeu " << (200 * Player.Mult) << " de XP" << endl;
    Player.EXP += (200 * Player.Mult);
    Player.LevelUp();

    PressEnter();
}

void SQM_Item(Heroi &Player, Stack &Mochila, List &Cinto) {
    cout << "Nome: " << Player.Nome << "    HP: " << Player.Vida_Atual << '/' << Player.Vida_Max << endl;  
    MostrarCinto(Cinto);
    MostrarMochila(Mochila);
    cout << "\n+----------Sala com item----------+" << endl;
    Elemento Item, Temp;
    char action;
    int pos;

    cout << Player.Nome << " encontrou um(a) ";
    MostrarItem(Item);

    cout << "\n(p - pegar | d - descartar)\nDigite sua escolha: ";
    cin >> action;

    if (action == 'd' || action == 'D') {
        cout << '\n' << Player.Nome << " descartou ";
        MostrarItem(Item);
        PressEnter();
        return;
    }

    cout << "\nOnde deseja guardar?" << endl;
    cout << "\n(m - mochila | c - cinto)\nDigite sua escolha: ";
    cin >> action;

    while (true) {
        switch (action) {
        case 'm':
        case 'M':
            Mochila.Push(Item);
            if (Item.tipo) {
                cout << '\n' << Item.Nome << " | Dano: " << Item.Pontos << " | Peso: " << Item.Peso;
            } else {
                cout << '\n' << Item.Nome << " | Cura: " << Item.Pontos << " | Peso: " << Item.Peso;
            }
            cout << " adicionado a mochila" << endl;
            PressEnter();
            return;
        case 'c':
        case 'C':
            if (Cinto.Full()) {
                cout << "\nCinto cheio!";

                trocar:

                cout << "Deseja trocar por algum item?" << endl;
                cout << "\n(s - sim | n - nao)\nDigite sua escolha: ";
                cin >> action;

                if (action == 'n' || action == 'N') {
                    cout << Player.Nome << " descartou ";
                    MostrarItem(Item);
                    PressEnter();
                    return;
                }

                cout << "\nPor qual item deseja trocar?" << endl;
                MostrarCinto(Cinto);
                cout << "\nDigite sua escolha: ";
                cin >> pos;

                if (pos <= Cinto.Size() && pos > 0) {
                    Cinto.Retrieve(pos, Temp);
                    cout << Player.Nome << " trocou ";
                    MostrarItem(Temp);
                    cout << " por ";
                    MostrarItem(Item);
                    Cinto.Replace(pos, Item);
                    PressEnter();
                    return;
                } else {
                    cout << "\nPosição inválida, tente novamente" << endl;
                }

            } else {
                if (Cinto.taPesado(Temp.Peso)) {
                    cout << "Item muito pesado, não cabe no cinto" << endl;
                    goto trocar;
                }
                
                Cinto.Insert(Cinto.Size() + 1, Item);
                if (Item.tipo) {
                    cout << Item.Nome << " | Dano: " << Item.Pontos << " | Peso: " << Item.Peso;
                } else {
                    cout << Item.Nome << " | Cura: " << Item.Pontos << " | Peso: " << Item.Peso;
                }
                cout << " adicionado ao cinto" << endl;
                PressEnter();
                return;
            }
            break;

        default:
            cout << "\nEscolha inválida, tente novamente" << endl;
            break;
        }
    }
}

void SQM_Vazio(Heroi &Player, Stack &Mochila, List &Cinto) {
    cout << "Nome: " << Player.Nome << "    HP: " << Player.Vida_Atual << '/' << Player.Vida_Max << endl; 
    MostrarCinto(Cinto);
    MostrarMochila(Mochila);
    cout << "\n+----------Sala Vazia----------+" << endl;

    Elemento Temp;
    char action;
    int pos;

    if (Mochila.Empty() && Cinto.Empty()) {
        cout << Player.Nome << " nao possui item, entao nao ha oque fazer aqui" << endl;
        PressEnter();
        return;
    }
    recomecar:
    cout << "Deseja remanejar ou usar seus itens?\n(s - sim | n - nao)\nDigite sua escolha: ";
    cin >> action;

    if (action == 'n' || action == 'N') {
        PressEnter();
        return;
    }

    while (true) {
        cout << "\nOnde deseja mexer?\n(m - mochila | c - cinto)\nDigite sua escolha: ";
        cin >> action;

        switch (action) {
        case 'm':
        case 'M':
            Mochila.Top(Temp);
            cout << "\nDeseja usar ou descartar: ";
            MostrarItem(Temp);
            cout << "\n(u - usar | d - descartar | v - voltar)\nDigite sua escolha: ";
            cin >> action;

            if (action == 'v' || action == 'V'){
                goto recomecar;
            }
        
            if (action == 'd' || action == 'D') {
                Mochila.Pop(Temp);
                cout << Player.Nome << " descartou ";
                MostrarItem(Temp);
                goto recomecar;
            }
            if (Temp.tipo) {
                cout << "\nNao e possivel usar ester tipo de item aqui" << endl;
                goto recomecar;
            } else {
                Mochila.Pop(Temp);
                Player.Curar(Temp.Pontos);
                goto recomecar;
            }
            break;
        case 'c':
        case 'C':
            cout << "Qual item deseja usar?\nDigite sua escolha: ";
            cin >> pos;

            if (pos <= Cinto.Size() && pos > 0) {
                Cinto.Retrieve(pos, Temp);
                if (Temp.tipo) {
                    cout << "\nNao e possivel usar ester tipo de item aqui" << endl;
                    goto recomecar;
                } else {
                    Mochila.Pop(Temp);
                    Player.Curar(Temp.Pontos);
                    goto recomecar;
                }
                break;
            }
            cout << "Posicao invalida, tente novamente" << endl;
            break;
        default:
            cout << "Escolha inválida, tente novamente" << endl;
            break;
        }
    }
    PressEnter();
}