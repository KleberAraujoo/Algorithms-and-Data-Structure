#include <iostream>
#include <vector>
using namespace std;

// Função para rastrear "pessoas" e suas divisões do array
void rastrearDivisao(const vector<int>& matriz, int inicio, int fim, int& contadorPessoa) {
    contadorPessoa++;
    cout << "Person " << contadorPessoa << " is given with these numbers: ";
    for (int i = inicio; i <= fim; i++) {
        cout << matriz[i] << " ";
    }
    cout << endl;
}

// Função de fusão para combinar duas partes ordenadas
void fusao(vector<int>& matriz, int inicio, int meio, int fim) {
    int tamanhoEsquerda = meio - inicio + 1;
    int tamanhoDireita = fim - meio;

    vector<int> esquerda(tamanhoEsquerda);
    vector<int> direita(tamanhoDireita);

    for (int i = 0; i < tamanhoEsquerda; i++)
        esquerda[i] = matriz[inicio + i];
    for (int j = 0; j < tamanhoDireita; j++)
        direita[j] = matriz[meio + 1 + j];

    int i = 0, j = 0, k = inicio;

    while (i < tamanhoEsquerda && j < tamanhoDireita) {
        if (esquerda[i] <= direita[j]) {
            matriz[k++] = esquerda[i++];
        } else {
            matriz[k++] = direita[j++];
        }
    }

    while (i < tamanhoEsquerda) {
        matriz[k++] = esquerda[i++];
    }

    while (j < tamanhoDireita) {
        matriz[k++] = direita[j++];
    }
}

// Função MergeSort com a modificação de rastrear as divisões
void mergeSort(vector<int>& matriz, int inicio, int fim, int& contadorPessoa) {

    if (inicio == 0 && fim == matriz.size() - 1) {
        rastrearDivisao(matriz, inicio, fim, contadorPessoa);
    }

    // Aqui, a divisão ocorre
    if (inicio >= fim) {
        return;
    }

    // Chama o rastrear divisão para a pessoa correspondente
    int meio = inicio + (fim - inicio) / 2;
    rastrearDivisao(matriz, inicio, meio, contadorPessoa);   // Primeira metade
    rastrearDivisao(matriz, meio + 1, fim, contadorPessoa);   // Segunda metade

    // Recursão para as duas metades
    mergeSort(matriz, inicio, meio, contadorPessoa);    // Primeira metade
    mergeSort(matriz, meio + 1, fim, contadorPessoa);   // Segunda metade

    // Faz a fusão das duas metades
    fusao(matriz, inicio, meio, fim);
}

int main() {
    int n;
    cin >> n;

    vector<int> matriz(n);
    for (int i = 0; i < n; i++) {
        cin >> matriz[i];
    }

    int contadorPessoa = 0;

    // Chama o mergeSort para ordenar o array
    mergeSort(matriz, 0, n - 1, contadorPessoa);

    // Exibe o array ordenado
    cout << "After Sorting the elements are: ";
    for (int i = 0; i < n; i++) {
        cout << matriz[i] << " ";
    }
    cout << endl;

    return 0;
}
