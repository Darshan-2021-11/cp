#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, n, t, c2;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> n;
    c2 = 0;
    for (u32 i = 0; i < n; ++i) {
      cin >> t;
      if (t == 2) ++c2;
    }
    if (c2 % 8 == 0) cout << "YES\n";
    else cout << "NO\n";
  }
}

