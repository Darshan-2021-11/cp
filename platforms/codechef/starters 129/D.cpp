#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, n, s, t, u, v;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> n >> s;
    if (s & 1 || n == 1 || s < n) cout << -1 << '\n';
    else {
      if (n & 1) {
        t = s - (n - 3);
        if (t < 6) {
          cout << -1 << '\n';
          continue;
        }
        u32 c1 = __builtin_popcount(t);
        if (c1 == 1) {
          if (n == 3) {
            cout << -1 << '\n';
            continue;
          }
          n -= 2;
          t = (s - 5 - (n - 2)) >> 1;
          cout << t << ' ' << t << ' ';
          cout << 3 << ' ' << 2 << ' ';
          n -= 2;
        } else {
          u32 ctz = __builtin_ctz(t);
          u = 1 << (ctz - 1);
          cout << (t >> 1) << ' ' << ((t >> 1) - u) << ' ';
          cout << u << ' ';
          n -= 3;
        }
      } else {
        t = (s - (n - 2)) >> 1;
        cout << t << ' ' << t << ' ';
        n -= 2;
      }
      for (u32 i = 0; i < n; ++i) cout << 1 << ' ';
      cout << '\n';
    }
  }
}

