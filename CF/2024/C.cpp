#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

// This function merges two sorted subarrays
// arr[l...m] and arr[m+1 .. r] and also counts
// inversions in the whole subarray arr[l..r]
long long countAndMerge(int arr[], int l, int m, int r){
    // Counts in two subarrays
    int n1 = m - l + 1, n2 = r - m;

    // Set up two vectors for left and right halves
    vector<long long> left(n1), right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = arr[i + l];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    // Initialize inversion count (or result)
    // and merge two halves
    long long res = 0;
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {

        // No increment in inversion count
        // if left[] has a smaller or equal element
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        }
        // If right is smaller, then it
        // is smaller than n1-i elements
        // because left[] is sorted
        else {
            arr[k++] = right[j++];
            res += (n1 - i);
        }
    }

    // Merge remaining elements
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    return res;
}

// Function to count inversions in the array
long long countInv(int arr[], int l, int r){
    long long res = 0;
    if (l < r) {
        int m = (r + l) / 2;

        // Recursively count inversions
        // in the left and right halves
        res += countInv(arr, l, m);
        res += countInv(arr, m + 1, r);

        // Count inversions such that greater
        // element is in the left half and
        // smaller in the right half
        res += countAndMerge(arr, l, m, r);
    }
    return res;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 100'000;
  int TC = 1, n, b[N << 1];
  pair<int, int> a[N];
  cin >> TC;
  while (TC--) {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
    sort(a, a + n, [&](pair<int, int> x, pair<int, int> y) {
        int t1 = x.first + x.second, t2 = y.second + y.first;
        if (t1 == t2) return x.first > y.first;
        else return t1 < t2;
        });
    for (int i = 0; i < n; ++i) b[i << 1] = a[i].first, b[i << 1 | 1] = a[i].second;
    for (int i = 0; i < n << 1; ++i) cout << b[i] << '\n';
    //cout << countInv(b, 0, (n << 1) - 1) << '\n';
  }
}
