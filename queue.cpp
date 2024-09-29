#include "queue.h"
#include <iostream>

using namespace std;

#ifndef QUEUE_H
#define QUEUE_H

List::List() {
    limitePeso = 16;
    count = 0;
}

bool List::Empty() {
    return count == 0;
}

bool List::Full() {
    return count == MaxList;
}

void List::Insert(int p, Elemento x) {
    if (Full()) {
        cout << "Lista cheia" << endl;
        abort();
    }
    if (p < 1 || p > count + 1) {
        cout << "Posicao invalida" << endl;
        abort();
    }
    for (int i = count; i >= p; i--) {
        Entry[i + 1] = Entry[i];
    }
    Entry[p] = x;
    count++;
}

void List::Delete(int p, Elemento &x) {
    if (Empty()) {
        cout << "Lista vazia" << endl;
        abort();
    }
    if (p < 1 || p > count) {
        cout << "Posicao invalida" << endl;
        abort();
    }
    x = Entry[p];
    for (int i = p; i < count; i++) {
        Entry[i] = Entry[i+1];
        count--;
    }
}

void List::Clear() {
    count = 0;
}

int List::Size() {
    return count;
}

void List::Retrieve(int p, Elemento &x) {
    if(p < 1 || p > count) {
        cout << "Posicao Invalida" << endl;
        abort();
    }
    x = Entry[p];
}

void List::Replace(int p, Elemento x) {
    if(p < 1 || p > count) {
        cout << "Posicao Invalida" << endl;
        abort();
    }
    Entry[p] = x;
}

bool List::taPesado(int novoPeso) {
    int pesoAtual = 0;

    for (int i = 1; i < count; i++) {
        Elemento Temp;
        Retrieve(i, Temp);
        pesoAtual += Temp.Peso;
    }
    
    return (pesoAtual + novoPeso > limitePeso);
}

#endif