#include "elemento.h"

class Stack {
    public:
        Stack();
        ~Stack();
        bool Empty();
        void Push(Elemento x);
        void Pop(Elemento &x);
        void Clear();
        void Top(Elemento &x);
        int Size();
    private:
        struct StackNode {
            Elemento Entry;
            StackNode *NextNode;
        };
        typedef StackNode *StackPointer;
        StackPointer top;
};