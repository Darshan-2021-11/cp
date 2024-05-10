#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int T = 1, n, t;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;
  t = 2;

  while (T--) {
    cin >> n;
    for (u32 i = 1; i <= n; ++i) {
      if (i == 2) cout << 1 << ' ' << 2 << '\n';
      else cout << i << ' ' << i << '\n';
    }
    cout << '\n';
  }
}
