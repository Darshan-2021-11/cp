#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 100'000;
  int TC = 1, n;
  int64_t res;
  cin >> TC;
  while (TC--) {
    int64_t sum[17] {};
    res = 0;
    cin >> n;
    for (int i = 0, t; i < n; ++i) {
      cin >> t;
      for (int j = 0; j <= 9; ++j) {
        sum[j] += t % 10;
        t /= 10;
      }
    }
    for (int i = 0; i <= 15; ++i) {
      if (sum[i] > 9) res += sum[i] / 10;
      sum[i + 1] += sum[i] / 10;
    }
    cout << res << '\n';
  }
}
