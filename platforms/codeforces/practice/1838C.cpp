#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, n, m, i, t;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> n >> m;
    if (n == 4) {
      for (u32 i = 1; i <= 4; ++i) {
        for (u32 j = i, k = 0; k < m; j += 4, ++k) cout << j << ' ';
        cout << '\n';
      }
    } else {
      for (i = 0; i < n; i += 2) {
        t = i * m;
        for (u32 j = 1; j <= m; ++j) cout << t + j << ' ';
        cout << '\n';
      }
      for (i = 1; i < n; i += 2) {
        t = i * m;
        for (u32 j = 1; j <= m; ++j) {
          cout << t + j << ' ';
        }
        cout << '\n';
      }
    }
    cout << '\n';
  }
}
