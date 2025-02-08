#include <iostream>
#include <cstring>
using namespace std;

typedef long long LL;
const int N = 1024;

// Vai definiri o número de elementos e a quantidade de estados
int quantidade_de_testes, quantidade_de_estados;

struct Estado {
    int inicio, fim;
    Estado(int inicio = 0, int fim = 0) : inicio(inicio), fim(fim) {}
};

// Vetor para armazenar os estados
Estado estados[N];

// Função para calcular o valor máximo entre dois inteiros
int maximo(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    cin >> quantidade_de_testes;

    while (quantidade_de_testes--) {
        cin >> quantidade_de_estados;

        // Vai ler os os valores de inicio e fim para cada estado
        for (int i = 0; i < quantidade_de_estados; ++i) {
            cin >> estados[i].inicio >> estados[i].fim;
        }

        int T = 1;

        // Vai analisar os estados
        for (int i = 0; i < quantidade_de_estados; ++i) {
            T = maximo(T, estados[i].inicio);  /
            if (estados[i].fim < T) {
                cout << "0 ";
            } else {
                cout << T << " ";
                ++T;
            }
        }
        cout << "\n";
    }

    return 0;
}
