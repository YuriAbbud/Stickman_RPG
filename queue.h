#ifndef QUEUE
#define QUEUE

#include "elemento.h"

const int MaxList = 3;

class List {
    public:
        List();
        //~List();
        bool Empty();
        bool Full();
        void Insert(int p, Elemento x);
        void Delete(int p, Elemento &x);
        void Clear();
        int Size();
        void Retrieve(int p, Elemento &x);
        void Replace(int p, Elemento x);
        bool Aguenta(int novoPeso);
    private:
        int limitePeso;
        int count;
        Elemento Entry[MaxList + 1];
};

#endif