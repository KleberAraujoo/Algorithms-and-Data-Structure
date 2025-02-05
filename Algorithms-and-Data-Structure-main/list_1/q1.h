#include <iostream>
#include <cmath>

using namespace std;

struct Array {
    long int fi;  // Início do intervalo
    long int se;  // Fim do intervalo
    int w;
};

void merge(long int arr[], long int l, long int m, long int r) {
    long int i, j, k;
    long int n1 = m - l + 1;
    long int n2 = r - m;
    long int L[n1], R[n2];

    // Copiar os dados para os arrays temporários
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    // Mesclar os arrays temporários de volta ao array original
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes de L[], se tiver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes de R[], se tiver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(long int arr[], long int l, long int r) {
    if (l < r) {
        long int m = l + (r - l) / 2;

        mergeSort(arr, l, m);        // Divisão da primeira metade
        mergeSort(arr, m + 1, r);    // Divisão da segunda metade
        merge(arr, l, m, r);         // Mescla as duas metades
    }
}

int main() {
    long int n;
    cin >> n;

    long int b[n], d[n];
    Array a[2 * n - 2];

    // Lendo os números
    for (long int k = 0; k < n; k++) {
        cin >> b[k];
        d[k] = b[k];
    }

    long int l = 0, r = 0;
    a[0].fi = 0;
    a[0].se = n;

    // Divisão dos intervalos
    while (l <= (2 * n - 2)) {
        float f = (a[l].se - a[l].fi) / 2.0;
        long int u = ceil(f);
        u += a[l].fi;

        if (a[l].se - a[l].fi != 1) {
            long int in = a[l].fi;
            long int n_ = a[l].se;

            r++;

            a[r].fi = in;
            a[r].se = u;

            r++;

            a[r].fi = u;
            a[r].se = n_;
        }

        l++;
    }

    for (long int v = 0; v <= (2 * n - 2); v++) {
        cout << v + 1 << " person is given with these numbers :";
        for (long int p = a[v].fi; p < a[v].se; p++) {
            cout << b[p] << " ";
        }
        cout << endl;
    }

    cout << "After Sorting the elements are : ";
    mergeSort(b, 0, n - 1);

    for (long int p = 0; p < n; p++) {
        cout << b[p] << " ";
    }
    cout << endl;

    return 0;
}
