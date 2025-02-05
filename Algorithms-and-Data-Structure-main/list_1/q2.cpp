#include <iostream>
#include <vector>
using namespace std;

// Função para mesclar (merge) duas partes do array
void merge(vector<int> &array, int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1; // Tamanho da metade esquerda
    int n2 = fim - meio;        // Tamanho da metade direita

    vector<int> esquerda(n1), direita(n2);

    for (int i = 0; i < n1; i++)
        esquerda[i] = array[inicio + i];
    for (int j = 0; j < n2; j++)
        direita[j] = array[meio + 1 + j];

    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) {
        if (esquerda[i] <= direita[j]) {
            array[k] = esquerda[i];
            i++;
        } else {
            array[k] = direita[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = esquerda[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = direita[j];
        j++;
        k++;
    }
}

// Função recursiva do Merge Sort
void mergeSort(vector<int> &array, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        // Ordenando as metades
        mergeSort(array, inicio, meio);
        mergeSort(array, meio + 1, fim);

        // Mesclando as metades ordenadas
        merge(array, inicio, meio, fim);
    }
}

// Função para contar os pares com diferença k
int contarParesComDiferencaK(const vector<int>& array, int k) {
    int contagem = 0;
    int i = 0, j = 1; // Ponteiros para percorrer o array

    while (j < array.size()) {
        int diff = array[j] - array[i];

        if (diff == k) {
            contagem++; // Encontrou um par com a diferença desejada
            i++;
            j++;
        } else if (diff < k) {
            j++; // Incrementa o ponteiro direito para aumentar a diferença
        } else {
            i++; // Incrementa o ponteiro esquerdo para diminuir a diferença
        }
    }

    return contagem;
}

int main() {
    int tam_array, k;
    cin >> tam_array >> k;

    vector<int> array(tam_array);
    for (int i = 0; i < tam_array; i++) {
        cin >> array[i];
    }

    // Chamando Merge Sort para ordenar o array
    mergeSort(array, 0, tam_array - 1);

    // Contando os pares com diferença igual a k
    int resultado = contarParesComDiferencaK(array, k);

    // Exibindo o resultado (número de pares)
    cout << resultado << endl;

    return 0;
}
