#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 1e5 + 5;  // Aqui é definindo o tamanho máximo que a entrada pode ter

char s[maxn];  // Vetor que vai armazenar a entrada
int proximo[maxn];  // Vetor que vai armazenar as posições

int main() {
    while (cin >> s) {
        proximo[0] = 0;
        int tamanho = strlen(s);

        // Loop para cada caractere da entrada
        for (int i = 1, pos = 0, ultimo = 0; i <= tamanho; ++i) {
            char c = s[i - 1];  // Pega o caractere atual da string

            if (c == '[') {
                // Se o caractere for '[', vai mover o cursor para o início
                pos = 0;
            }
            else if (c == ']') {
                // Se o caractere for ']', vai mover o cursor para a última posição
                pos = ultimo;
            }
            else {
                // Se for um caractere comum, vai fazer a inserção na posição correta
                proximo[i] = proximo[pos];
                proximo[pos] = i;
                if (pos == ultimo) {
                    ultimo = i;
                }
                pos = i;
            }
        }

        // Loop que vai imprimir os caracteres a partir da posição inicial
        for (int i = proximo[0]; i; i = proximo[i]) {
            cout << s[i - 1];
        }

        cout << '\n';
    }

    return 0;
}
