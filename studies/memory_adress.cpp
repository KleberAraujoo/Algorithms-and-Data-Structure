#include <iostream>
using namespace std;

void modificarValor(int x) {
    x = 100; // Modifica apenas a cópia
}

void modificarValor_2(int& y) {
    y = 600; // Modifica o valor original porque é passada por referência
}

void funcaonumeroconst(const int z) {
    // z = 10000;   Se colocar z = 1000 vai da erro pois a variavel z é uma constante que recebe a variavel numero_const = 1000 por isso não pode ser modificada
    cout << "Valor com const: " << z  << '\n';
}

int main() {
    // Endereço de memória refere-se a onde uma variável está armazenada no espaço de memória
    // Usar o operador & para obter o endereço de memória de uma variável

    int numero = 42;
    cout << "O valor de numero: " << numero << endl;
    cout << "O endereço de numero: " << &numero << endl; // Mostra o endereço de memória

    // Função recebendo argumento, mas não modifica o valor original, pois na função é passado uma cópia
    modificarValor(numero);
    cout << "Valor de numero original após modificarValor: " << numero << endl; // Exibe 42, pois a alteração foi na cópia

    // Função recebendo argumento, mas sendo modificado porque é passado por referência
    int novo_numero = 50;
    modificarValor_2(novo_numero);
    cout << "Valor de novo_numero após modificarValor_2: " << novo_numero << endl; // Exibe 500, pois o valor original foi alterado

    int numero_const = 100;
    funcaonumeroconst(numero_const);


    return 0;
}
