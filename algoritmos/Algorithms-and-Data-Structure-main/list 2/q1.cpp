#include <iostream>
#include <unordered_map>
#include <climits>
#include <string>
#include <vector>

using namespace std;

vector<string> split_string(string input_string) {
    vector<string> splits;
    size_t pos = 0;
    while ((pos = input_string.find(' ')) != string::npos) {
        splits.push_back(input_string.substr(0, pos));
        input_string.erase(0, pos + 1);
    }
    splits.push_back(input_string);
    return splits;
}


void sort_descending(vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        for (size_t j = i + 1; j < vec.size(); j++) {
            if (vec[i] < vec[j]) {
                swap(vec[i], vec[j]);
            }
        }
    }
}

void reverse_vector(vector<int>& vec) {
    int left = 0;
    int right = vec.size() - 1;
    while (left < right) {
        swap(vec[left], vec[right]);
        left++;
        right--;
    }
}

int lilysHomework(vector<int> arr_orig) {
    int result = INT_MAX;

    vector<int> sorted(arr_orig);
    sort_descending(sorted);


    for (int rev = 0; rev < 2; rev++) {
        int curSwap = 0;
        if (rev) {
            reverse_vector(sorted);
        }

        vector<int> arr(arr_orig);

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

        result = min(result, curSwap);
    }

    return result;
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
