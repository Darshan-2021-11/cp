#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, n, ans;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15),
      cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> n;
    ans = 0;
    for (u32 i = 1, j = 1; i <= n; ++i, j += 2) ans += i * j;
    cout << ans << ' ';
    cout << (n << 1) << '\n';
    ans = n;
    for (u32 i = 1; i <= n; ++i, --ans) {
      cout << 1 << ' ' << ans << ' ';
      for (u32 j = 1; j <= n; ++j) cout << j << ' ';
      cout << '\n';
      cout << 2 << ' ' << ans << ' ';
      for (u32 j = 1; j <= n; ++j) cout << j << ' ';
      cout << '\n';
    }
  }
}
