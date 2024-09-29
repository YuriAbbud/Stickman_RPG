#include "dynamic_stack.h"
#include <iostream>
using namespace std;

#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

Stack::Stack() {
    top = NULL;
}

Stack::~Stack() {
    Elemento x;
    while (!Empty()) {
        Pop(x);
    }
}

bool Stack::Empty() {
    return top == NULL;
}

void Stack::Push(Elemento x) {
    StackPointer p;
    p = new StackNode;
    if(p == NULL) {
        cout << "Memoria insuficiente";
        abort();
    }
    p->Entry = x;
    p->NextNode = top;
    top = p;
}

void Stack::Pop(Elemento &x) {
    StackPointer p;
    if (Empty()) {
        cout << "Pilha vazia";
        abort();
    }
    x = top->Entry;
    p = top;
    top = top->NextNode;
    delete p;
}

void Stack::Clear() {
    Elemento x;
    while(!Empty()) {
        Pop(x);
    }
}

void Stack::Top(Elemento &x) {
    if(Empty()) {
        cout << "Pilha vazia";
        abort();
    }
    x = top->Entry;
}

int Stack::Size() {
    StackPointer p;
    int s = 0;
    p = top;
    while(p != NULL) {
        s++;
        p = p->NextNode;
    }
    return s;
}

#endif