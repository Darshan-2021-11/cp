#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 200'000;
  int TC = 1, n;
  char c;
  const char *ans[] = { "NO\n", "YES\n" };
  vector<bool> a(N);
  bool yes;
  cin >> TC;
  while (TC--) {
    yes = false;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> c; a[i] = c ^ '0';
    }
    if (n == 2) {
      cout << ans[a[0] | a[1]];
      continue;
    }
    for (int i = 2; i < n; ++i) yes |= a[i - 2] & a[i - 1] & a[i];
    for (int i = 3; i < n; ++i) yes |= (!a[i - 3]) & a[i - 2] & a[i - 1] & (!a[i]);
    yes |= a[0];
    yes |= a[n - 1];
    cout << ans[yes];
  }
}
