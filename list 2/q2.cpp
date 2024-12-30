#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    // Implementação do algoritmo Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Troca dos elementos
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, m;

    // Leitura do número de elementos
    cin >> n;

    vector<int> a(n);  // Usando vetor dinâmico (mais adequado no C++)
    vector<long long> psum(n + 1, 0);  // Somas prefixadas
    vector<long long> nsum(n + 2, 0);  // Somas sufixadas

    // Leitura do vetor a
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Ordenação manual usando bubbleSort
    bubbleSort(a);

    // Calculando as somas prefixadas
    for (int i = 1; i <= n; i++) {
        psum[i] = psum[i-1] + a[i-1];  // Lembre-se que 'a' começa do índice 0  
    }

    // Calculando as somas sufixadas
    for (int i = n - 1; i >= 0; i--) {
        nsum[i+1] = nsum[i+2] + a[i];
    }

    // Leitura do número de consultas
    cin >> m;

    int temp;
    // Processando as consultas
    for (int i = 0; i < m; i++) {
        cin >> temp;
        // Imprime a soma de acordo com o cálculo dado
        cout << nsum[n - temp + 2] + psum[n - temp] << endl;
    }

    return 0;
}
