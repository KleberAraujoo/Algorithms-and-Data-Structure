#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Fenwick Tree (BIT) Implementation
class FenwickTree {
private:
    vector<int> tree;
    int size;

public:
    FenwickTree(int n) : size(n) {
        tree.resize(n + 1, 0);
    }

    void update(int index, int value) {
        while (index <= size) {
            tree[index] += value;
            index += index & -index;
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }

    int rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};

// Structure to hold queries
struct Query {
    int left, right, value, index;
    bool operator<(const Query &other) const {
        return value < other.value;
    }
};

// Main function to solve the problem
int longestSubsequence(vector<int> &arr) {
    int n = arr.size();
    vector<pair<int, int>> elements;
    for (int i = 0; i < n; ++i) {
        elements.push_back({arr[i], i + 1});
    }

    // Sort elements by value
    sort(elements.begin(), elements.end());

    vector<Query> queries;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int minValue = min(arr[i], arr[j]);
            queries.push_back({i + 2, j, minValue, (int)queries.size()});
        }
    }

    // Sort queries by value
    sort(queries.begin(), queries.end());

    FenwickTree fenwickTree(n);
    vector<int> results(queries.size(), 0);

    int elementIndex = 0;
    for (const auto &query : queries) {
        while (elementIndex < n && elements[elementIndex].first <= query.value) {
            fenwickTree.update(elements[elementIndex].second, 1);
            ++elementIndex;
        }

        results[query.index] = fenwickTree.rangeQuery(query.left, query.right);
    }

    int maxResult = 0;
    for (const auto &result : results) {
        maxResult = max(maxResult, result + 2); // Include the two boundary elements
    }

    return maxResult;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << longestSubsequence(arr) << endl;
    return 0;
}