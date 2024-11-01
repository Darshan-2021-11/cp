#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 200'001;
  int64_t TC = 1, n, a[N], an;
  cin >> TC;
  while (TC--) {
    cin >> n;
    if (n == 1) {
      cout << 0 << '\n';
      cout << 1 << '\n';
      continue;
    }
    if (n == 2) {
      cout << 2 << '\n';
      cout << 1 << ' ' << 2 << '\n';
      continue;
    }
    if (n == 3) {
      cout << 2 << '\n';
      cout << 1 << ' ' << 2 << ' ' << 3 << '\n';
      continue;
    }
    if (n == 4) {
      cout << 6 << '\n';
      cout << 1 << ' ' << 2 << ' ' << 3 << ' ' << 4 << '\n';
      continue;
    }
    an = 1;
    int64_t h = (1LL << (63 - __builtin_clzll(n)));
    if (n & 1) {
      cout << n << ' ';
      array<int64_t, 4> x = { -1, 1, n - 1, n };
      for (int i = 1; i <= n; ++i) {
        if (find(x.begin(), x.end(), i) == x.end()) {
          if ((i & 1) && x[0] == -1) { x[0] = i; continue; }
          a[an++] = i;
        }
      }
      for (const int64_t &i: x) a[an++] = i;
    } else {
      cout << (h << 1) - 1 << ' ';
      array<int64_t, 5> x = { -1, 1, h - 2, h - 1, h };
      for (int i = 1; i <= n; ++i) {
        if (find(x.begin(), x.end(), i) == x.end()) {
          if ((i & 1) && x[0] == -1) { x[0] = i; continue; }
          a[an++] = i;
        }
      }
      for (const int64_t &i: x) a[an++] = i;
    }
    cout << '\n';
    for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
    cout << '\n';
  }
}
