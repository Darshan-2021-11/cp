#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u64 a[u32(2e5)], T = 1, n, t, tmp;
bool b[u32(2e5) + 1], disrupted, yes;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    disrupted = false, yes = true;
    cin >> n;
    for (u32 i = 1; i < n; ++i) {
      cin >> a[i];
      tmp = a[i] - a[i - 1];
      if (tmp > n || b[tmp]) {
        if (disrupted) {
          yes = false;
        }
        disrupted = true;
        t = tmp;
      } else b[tmp] = true;
    }
    for (u32 i = 1; i <= n; ++i) if (!b[i]) t -= i;
    if (yes && (!disrupted || !t)) cout << "YES\n";
    else cout << "NO\n";
    for (u32 i = 1; i <= n; ++i) b[i] = false;
  }
}
