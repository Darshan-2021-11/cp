#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int TC = 1, n, k, odd;
  cin >> TC;
  while (TC--) {
    odd = 0;
    cin >> n >> k;
    if (n < k) odd = (n >> 1) + (n & 1);
    else odd = (k >> 1) + ((k & 1) && (n & 1));
    cout << (odd & 1 ? "NO\n": "YES\n");
  }
}
