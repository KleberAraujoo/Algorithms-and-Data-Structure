#include <bits/stdc++.h>
using namespace std;

struct Query {
    int l, r, x, index;
};

struct Arrays {
    int val, index;
};

bool cmp1(Query q1, Query q2) {
    return q1.x < q2.x;
}

bool cmp2(Arrays x, Arrays y) {
    return x.val < y.val;
}

void update(int* Fenwick, int index, int val, int n) {
    while (index <= n) {
        Fenwick[index] += val;
        index += index & (-index);
    }
}

int query(int* Fenwick, int index, int n) {
    int sum = 0;
    while (index > 0) {
        sum = sum + Fenwick[index];
        index -= index & (-index);
    }
    return sum;
}

int maxLength(int n, vector<int>& v) {
    int where[n + 2];
    memset(where, 0, sizeof where);

    Arrays arr[n];

    for (int i = 1; i <= n; ++i) {
        v[i - 1] = v[i - 1] - 1;
        int x = v[i - 1];
        where[x] = i - 1;
        arr[i - 1].val = x;
        arr[i - 1].index = i - 1;
    }

    if (n <= 2) {
        cout << n << endl;
        return 0;
    }

    int left = n, right = 0, mx = 0;

    Query queries[4 * n];
    int j = 0;

    for (int i = n - 1; i >= 0; --i) {
        left = min(left, where[i]);
        right = max(right, where[i]);

        int diff = right - left;

        if (diff == 0 || diff == 1) {
            continue;
        }

        int val1 = v[left];
        int val2 = v[right];
        int minn = min(val1, val2);

        queries[j].l = left + 1;
        queries[j].r = right - 1;
        queries[j].x = minn;
        queries[j].index = j;
        ++j;
    }

    int Fenwick[n + 1];
    memset(Fenwick, 0, sizeof Fenwick);

    int q = j - 1;

    sort(arr, arr + n + 1, cmp2);
    sort(queries, queries + q + 1, cmp1);

    int curr = 0;
    int ans[q];
    memset(ans, 0, sizeof ans);

    for (int i = 0; i <= q; ++i) {
        while (arr[curr].val <= queries[i].x and curr < n) {
            update(Fenwick, arr[curr].index + 1, 1, n);
            curr++;
        }
        ans[queries[i].index] = query(Fenwick, queries[i].r + 1, n) - query(Fenwick, queries[i].l, n);
    }

    for (int i = 0; i <= q; ++i) {
        mx = max(mx, ans[i]);
    }

    mx = mx + 2;
    return mx;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    cout << maxLength(n, v) << endl;
    return 0;
}