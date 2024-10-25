#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 200'000;
  int TC = 1, a[N], pm[N], n, m, t, bad;
  char c;
  bitset<N> s;
  cin >> TC;
  while (TC--) {
    bad = 0;
    cin >> n >> m;
    cin >>  a[0], pm[0] = a[0];
    for (int i = 1; i < n; ++i) cin >> a[i], pm[i] = max(a[i], pm[i - 1]);
    for (int i = 0; i < n; ++i) cin >> c, s[i] = c == 'R';
    for (int i = 1; i < n; ++i) bad += (!a[i - 1]) & a[i];
    while (m--) {
      cin >> t;
      s.flip(t - 1);
    }
  }
}
