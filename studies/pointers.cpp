#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int* ptr = &x; // ptr armazena o endereço de memória de x

    cout << "Valor de x: " << x << endl;        // Exibe o valor de x
    cout << "Endereço de x: " << &x << endl;    // Exibe o endereço de memória de x
    cout << "Valor armazenado em ptr: " << ptr << endl; // Exibe o endereço armazenado no ponteiro
    cout << "Valor apontado por ptr: " << *ptr << endl; // Exibe o valor de x (desreferenciação)

    return 0;
}
