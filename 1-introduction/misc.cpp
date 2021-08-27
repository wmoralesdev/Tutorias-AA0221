#include <iostream>
using namespace std;

// typedef - Crear tipos personalizados o cambiar el nombre de los tipos de datos existentes
// para mejorar la legibilidad de codigo
typedef int colors;

struct node {
    int data;
    node* next;
};
typedef node* list;

template <class TuPrima>
void printGenericData(TuPrima var);

int main(void) {
    list studentsRegistry = NULL;
    
    // Var Implicitas = se declaran con un valor inicial y el compilador se encarga de asignarles el tipo
    // automaticamente

    // C# var a = 20.90f; -> Float
    // var name = "Walter"; -> String

    // auto integer = 1;
    // auto str = "Hola banda";
    // auto character = 'a';

    // colors red = 10;

    int integer = 10;
    double db = 20.0;
    string name = "Walter";
    char initial = 'w';

    printGenericData(integer);
    printGenericData(db);
    printGenericData(name);
    printGenericData(initial);

    return 0;
}

template <class TuPrima>
void printGenericData(TuPrima var) {
    cout << var << endl;
}

void printNonGenericData(int var) {
    cout << var;
}