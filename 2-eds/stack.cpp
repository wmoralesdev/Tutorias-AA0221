#include <iostream>
using namespace std;

// Pila generica
template <class T>
struct node {
    T data;
    node<T> *next;

    // Siempre debe existir un constructor por defecto (vacio)
    node() {
        next = NULL;
    }

    // Constructor con dato
    node(T dataArg) : data(dataArg) { next = NULL; }

    // node(T data) {
    //     this->data = data;
    //     next = NULL;
    // }
};

template <class T>
void push(node<T>** stack, T data);

template <class T>
void show(node<T>* stack);

int main(void) {
    node<int>* stack = NULL;
    // node<char>* stack2 = NULL;

    int a = 20;
    int* ptr = &a;

    cout << ptr << endl;
    cout << *ptr << endl;
    cout << &a << endl;
    cout << &ptr << endl;

    // cout << stack << endl;
    // cout << &stack << endl;

    // // Insertar elementos
    // push(&stack, 1);
    // push(&stack, 2);
    // push(&stack, 3);
    // push(&stack, 4);

    // push(&stack2, 'a');
    // push(&stack2, 'b');
    // push(&stack2, 'c');
    // push(&stack2, 'd');
    
    // show(stack);
    // show(stack2);

    return 0;   
}

// Push
template <class T>
void push(node<T>** stack, T data) {
    node<T>* newNode = new node<T>(data);

    newNode->next = *stack;
    *stack = newNode;
}

// Show
template <class T>
void show(node<T>* stack) {
    if(stack) {
        cout << stack->data << "\t";
        show(stack->next);
    }
    else
        cout << endl;
}

// Pop - Eliminar el elemento al tope de la pila y retornar su valor
template <class T>
T pop(node<T>** stack) {
    T data = (*stack)->data;
    *stack = (*stack)->next;
    
    return data;
}

// Peek - Top / Ver el elemento al tope de la pila
template <class T>
T peek(node<T>* stack) {
    return stack->data;
}

// Size
template <class T>
int size(node<T>* stack) {
    if(stack)
        return 1 + size(stack->next);
    else
        return 0;
}

// Empty
template <class T>
bool empty(node<T>* stack) {
    return !stack; // stack == NULL
}