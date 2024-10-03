#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 5000;
  int TC = 1, n, x[N][N], a[N];
  cin >> TC;
  while (TC--) {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) x[i][j] = a[i] ^ a[j];
    }
  }
}
