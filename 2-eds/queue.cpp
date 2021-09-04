#include <iostream>
using namespace std;

// Cola generica
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
void enqueue(node<T>** queue, T data);

template <class T>
void show(node<T>* queue);

int main(void) {
    node<int>* queue = NULL;
    node<char>* queue2 = NULL;

    int a = 20;
    int* ptr = &a;

    cout << ptr << endl;
    cout << *ptr << endl;
    cout << &a << endl;
    cout << &ptr << endl;

    // cout << queue << endl;
    // cout << &queue << endl;

    // // Insertar elementos
    // push(&queue, 1);
    // push(&queue, 2);
    // push(&queue, 3);
    // push(&queue, 4);

    // push(&queue2, 'a');
    // push(&queue2, 'b');
    // push(&queue2, 'c');
    // push(&queue2, 'd');
    
    // show(queue);
    // show(queue2);

    return 0;   
}

// Push
// Recibir la cola por referencia de puntero (ref de direccion de memoria)
template <class T>
void enqueue(node<T>** queue, T data) {
    node<T>* newNode = new node<T>(data);

    if(!*queue) {
        *queue = newNode;
    }
    else {
        // Encontrar el ultimo elemento
        node<T>* last = *queue;

        // 1 -> 2 -> 3 -> 4 -> NULL

        while(last->next) {
            last = last->next;
        }

        // El siguiente al ultimo sea el nuevo
        last->next = newNode;
    }
}

// Show
template <class T>
void show(node<T>* queue) {
    if(queue) {
        cout << queue->data << "\t";
        show(queue->next);
    }
    else
        cout << endl;
}

// Pop - Eliminar el elemento al tope de la Cola y retornar su valor
template <class T>
T dequeue(node<T>** queue) {
    T data = (*queue)->data;
    *queue = (*queue)->next;
}

// Peek - Top / Ver el elemento al tope de la Cola
template <class T>
T front(node<T>* queue) {
    return queue->data;
}

// Recibir la cola por valor
template <class T>
T back(node<T>* queue) {
    while(queue->next) {
        queue = queue->next;
    }

    return queue->data;
}

// Size
template <class T>
int size(node<T>* queue) {
    if(queue)
        return 1 + size(queue->next);
    else
        return 0;
}

// Empty
template <class T>
bool empty(node<T>* queue) {
    return !queue; // queue == NULL
}