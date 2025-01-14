#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

void merge(vector<int>& vec, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (vec[i] <= vec[j]) {
            temp[k++] = vec[i++];
        } else {
            temp[k++] = vec[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = vec[i++];
    }

    while (j <= right) {
        temp[k++] = vec[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++) {
        vec[i] = temp[k];
    }
}

void mergeSort(vector<int>& vec, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);
        merge(vec, left, mid, right);
    }
}

void reverseVector(vector<int>& vec) {
    size_t left = 0;
    size_t right = vec.size() - 1;
    while (left < right) {
        swap(vec[left], vec[right]);
        left++;
        right--;
    }
}

int countSwaps(vector<int> arr, const vector<int>& sorted) {
    int curSwap = 0;
    unordered_map<int, int> val2pos;

    for (int i = 0; i < arr.size(); i++) {
        val2pos[arr[i]] = i;
    }

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == sorted[i]) {
            continue;
        }

        int ai = arr[i];
        int si = sorted[i];

        swap(arr[i], arr[val2pos[si]]);
        curSwap++;

        val2pos[ai] = val2pos[si];
        val2pos[si] = i;
    }

    return curSwap;
}

int lilysHomework(vector<int> arr_orig) {
    vector<int> sorted(arr_orig);

    mergeSort(sorted, 0, sorted.size() - 1);

    int swapsNormal = countSwaps(arr_orig, sorted);

    reverseVector(sorted);

    int swapsReversed = countSwaps(arr_orig, sorted);

    return min(swapsNormal, swapsReversed);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = lilysHomework(arr);
    cout << result << "\n";

    return 0;
}
