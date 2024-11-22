#include <iostream>
using namespace std;

void sort(int array[], int size);

int main () {

    int array[] = {2,5,1,3,4};

    int size = sizeof(array) / sizeof(array[0]);

    sort(array, size);

    for (int element : array) {
        cout << element << " ";
    }

    return 0;
}

void sort(int array[], int size) {

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {

            // troca de elementos
            if (array[j] > array[j + 1])  // verifica se o valor em questão do array é maior que valor seguinte do array, se sim, entra no if
                int temp = array[j];    // armazena o valor do array em uma variável temporária
                array[j] = array[j + 1]; // o valor do array atual recebe o proximo valor do array
                array[j + 1] = temp; // o proximo valor do array recebe a variável temporária
            // temos um array {5,2}
            // Então array[j] é 5 e array[j + 1] é 2
            // como array[j] é maior que array[j+1] então entra no if
            // temp recebe 5 do array[j] e o array [j] recebe 2 do array[j+1]
            // array[j+1] recebe 5 do temp, ficando assim {1,5}
        }
    }
}
