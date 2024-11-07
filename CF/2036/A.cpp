#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 50;
  int TC = 1, n, a[N];
  bool yes;
  cin >> TC;
  while (TC--) {
    yes = true;
    cin >> n;
    cin >> a[0];
    for (int i = 1; i < n; ++i) {
      cin >> a[i];
      yes &= abs(a[i] - a[i - 1]) == 5 || abs(a[i] - a[i - 1]) == 7;
    }
    cout << (yes ? "YES\n": "NO\n");
  }
}
