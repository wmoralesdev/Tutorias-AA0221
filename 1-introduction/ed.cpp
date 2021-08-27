#include <iostream>
using namespace std;

void changeByPtrRef(int* a);
void changeByValue(int a);
void changeByRef(int& a);

// Punteros
int main(void) {
    int integer = 10;
    
    // Puntero = una variable que contiene la direccion de memoria en la cual se almacena un valor
    // integerPtr contendra o apuntara a la direccion de mem de integer
    // int* integerPtr = &integer;

    // acceder el valor que existe dentro de la direccion de mem a la cual esta apuntando integerPtr
    // cout << *integerPtr << endl;
    // cout << integerPtr << endl;

    // int toChange = 20;

    // cout << "Before: " << toChange << endl;
    // changeByValue(toChange);
    // cout << "After: " << toChange << endl << endl;

    // cout << "Before: " << toChange << endl;
    // changeByPtrRef(&toChange);
    // cout << "After: " << toChange << endl << endl;

    // cout << "Before: " << toChange << endl;
    // changeByRef(toChange);
    // cout << "After: " << toChange << endl;

    // Arrays as ptr
    int* ptrArray = new int[4];

    for(int i = 0; i < 4; i++) {
        ptrArray[i] = i + 1;
    }

    for(int i = 0; i < 4; i++) {
        cout << *(ptrArray + i) << endl;
    }

    return 0;
}

// Por valor
void changeByValue(int a) {
    a = 666;
}

// Por referencia - Por referencia de puntero - Acceso completo a cualquier tipo de modificacion de lo que sea que este
// en dicha direccion de mem
void changeByPtrRef(int* a) {
    *a = 666;
}

// Por referencia - Permisos de modificacion del valor que hay en esta variable
void changeByRef(int& a) {
    a = 777;
}