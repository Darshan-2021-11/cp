#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, n, a[(u32)4e5 + 1], pmap[(u32)4e5 + 1], t, ans, components;
bool visited[(u32)4e5 + 1];
const u32 MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    components = 0, ans = 1;
    cin >> n;
    for (u32 i = 1; i <= n; ++i) visited[i] = false, cin >> a[i];
    for (u32 i = 1; i <= n; ++i) {
      cin >> t;
      pmap[a[i]] = t;
    }
    for (u32 i = 1; i <= n; ++i) {
      if (visited[i]) continue;
      t = i;
      do visited[t] = true; while (!visited[t = pmap[t]]);
      ans <<= 1;
      if (ans >= MOD) ans -= MOD;
    }
    cout << ans << '\n';
  }
}
