#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

struct segment {
    int prefixSum, suffixSum, totalSum, maxSum;
    void mergeSegment(segment left, segment right) {
        prefixSum = max(left.prefixSum, left.totalSum + right.prefixSum);
        suffixSum = max(right.suffixSum, right.totalSum + left.suffixSum);
        totalSum = left.totalSum + right.totalSum;
        maxSum = max(prefixSum, max(suffixSum, max(left.maxSum, max(right.maxSum, left.suffixSum + right.prefixSum))));
    }
} segmentTree[4 * N];

void build(int lo, int hi, int i, vector<int>& arr) {
    if (lo > hi)
        return;
    if (lo == hi) {
        segmentTree[i].prefixSum = segmentTree[i].suffixSum = segmentTree[i].totalSum = segmentTree[i].maxSum = arr[lo];
        return;
    }
    int mid = lo + hi >> 1;
    build(lo, mid, 2 * i + 1, arr);
    build(mid + 1, hi, 2 * i + 2, arr);
    segmentTree[i].mergeSegment(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
}

segment query(int lo, int hi, int l, int r, int i) {
    segment ans;
    ans.prefixSum = ans.suffixSum = ans.totalSum = ans.maxSum = INT_MIN;
    if (lo > hi || lo > r || hi < l) {
        return ans;
    }
    if (l <= lo && hi <= r) {
        return segmentTree[i];
    }
    int mid = lo + hi >> 1;
    if (l > mid) {
        return query(mid + 1, hi, l, r, 2 * i + 2);
    }
    if (r <= mid) {
        return query(lo, mid, l, r, 2 * i + 1);
    }
    ans.mergeSegment(query(lo, mid, l, r, 2 * i + 1), query(mid + 1, hi, l, r, 2 * i + 2));
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build(0, n - 1, 0, arr);
    int q;
    cin >> q;
    int x, y;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        cout << query(0, n - 1, x - 1, y - 1, 0).maxSum << "\n";
    }
    return 0;
}