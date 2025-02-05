#include <iostream>
#include <cmath>
using namespace std;

int main () {

    double num_1 = 4;
    double num_2 = 12.25;
    double num_3 = 0.0121;

    double result_num_1 = sqrt(num_1);
    double result_num_2 = sqrt(num_2);
    double result_num_3 = sqrt(num_3);

    cout << "A raiz quadrada de " << num_1 << " é: " << result_num_1 << endl;
    cout << "A raiz quadrada de " << num_2 << " é: " << result_num_2 << endl;
    cout << "A raiz quadrada de " << num_3 << " é: " << result_num_3 << endl;

    double num_4;
    cout << "Digite um número: ";
    cin >> num_4;

    double result_num_4 = sqrt(num_4);
    cout << "A raiz quadrada de " << num_4 << " é: " << result_num_4 << endl;

    return 0;
}