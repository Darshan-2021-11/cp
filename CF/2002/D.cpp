#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 300'001;
static i32 TC, n, q, h, x, y, u, a[N], head[N], adj[N], nxt[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cin >> n >> q;
    h = __builtin_popcount(n);
    for (i32 i = 2, t = 1; i <= n; ++i) {
      cin >> u;
      adj[t] = u, nxt[t] = head[i], head[i] = t++;
    }
    for (i32 i = 1; i <= n; ++i) cin >> a[i];
    while (q--) {
      cin >> x >> y;
      swap(a[x], a[y]);
    }
  }
}

