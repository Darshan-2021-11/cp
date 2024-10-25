#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int64_t TC = 1, n;
  cin >> TC;
  while (TC--) {
    cin >> n;
    cout << 1;
    for (int i = 1; i < n; ++i) cout << 0;
    cout << '\n';
  }
}
