#include <iostream>
using namespace std;

int main(void) {
    double d = 24.4;

    cout << (isInteger(d) ? "true" : "false") << endl;

    return 0;
}

bool isInteger(double d) {
    return d == (int)d;
}