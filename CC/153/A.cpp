#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  int TC = 1, c[3];
  bool yes;
  cin >> TC;
  while (TC--) {
    yes = true;
    for (int i = 0; i < 3; ++i) cin >> c[i];
    yes &= c[0] <= c[1] + c[2];
    yes &= c[1] <= c[0] + c[2];
    yes &= c[2] <= c[0] + c[1];
    cout << (yes ? "YES\n": "NO\n");
  }
}
