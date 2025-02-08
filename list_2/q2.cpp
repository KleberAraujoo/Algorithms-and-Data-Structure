#include <iostream>
#define endl '\n'
using namespace std;

void swap(long long int *vec, long long int a, long long int b) {
    long long int temp = vec[a];
    vec[a] = vec[b];
    vec[b] = temp;
}

// Função insertion sort
void inssort(long long int *vec, long long int l, long long int r) {
    for (int i = l + 1; i < r; i++) {
        for (int j = i; j > l; j--) {
            if (vec[j] < vec[j - 1]) {
                int temp = vec[j];
                vec[j] = vec[j-1];
                vec[j-1] = temp;
            }
        }
    }
}

// Função para fazer o particionamento no quicksort
long long int partition(long long int *vec, long long int l, long long int r, long long int val) {
    do {
        while (vec[++l] < val);
        while (l < r && vec[--r] > val);
        swap(vec, l, r);
    } while (l < r);
    return l;
}

// Função Quicksort
void quicksort(long long int *vec, long long int l, long long int r) {
    if (l >= r) return;
    if (r - l <= 9) {
        inssort(vec, l, r);
    }
    long long int p = (l + r) / 2;
    swap(vec, r, p);
    int k = partition(vec, l - 1, r, vec[r]);
    swap(vec, k, r);
    quicksort(vec, l, k - 1);
    quicksort(vec, k + 1, r);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    long long int choco, coupon, sum = 0, i;
    cin >> choco;

    long long int price[choco];  // Array para armazenar os preços dos chocolates
    for (int i = 0; i < choco; i++) {
        cin >> price[i];  // Lê o preço de cada chocolate
    }

    cin >> coupon;
    long long int number[coupon];  // Array para armazenar os valores dos cupons
    for (int i = 0; i < coupon; i++) {
        cin >> number[i];
    }

    quicksort(price, 0, choco - 1);  // Ordena os preços dos chocolates

    for (int i = 0; i < choco; i++) {
        sum += price[i];
    }

    for (int i = 0; i < coupon; i++) {
        cout << sum - price[choco - number[i]] << endl;
    }

    return 0;
}
