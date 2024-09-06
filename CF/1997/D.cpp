#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i32 TC, n, a[N], head[N], adj[N << 1], nxt[N << 1];
static i32 dfs(i32 c, i32 p) {
  i32 mn = INT_MAX, u, t;
  for (i32 i = head[c]; i; i = nxt[i]) if (p - (u = adj[i])) {
    t = dfs(u, c);
    mn = min(mn, t);
  }
  if (mn == INT_MAX) mn = a[c];
  if (c == 1) return a[c] + mn;
  if (a[c] < mn) {
    return a[c] = (a[c] + mn) >> 1;
  } else {
    return a[c] = mn;
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cin >> n;
    for (i32 i = 1; i <= n; ++i) cin >> a[i], head[i] = 0;
    for (i32 i = 2, t = 1, u; i <= n; ++i) {
      cin >> u;
      adj[t] = i, nxt[t] = head[u], head[u] = t++;
      adj[t] = u, nxt[t] = head[i], head[i] = t++;
    }
    cout << dfs(1, 1) << '\n';
  }
}
