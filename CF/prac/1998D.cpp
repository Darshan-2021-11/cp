#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'002;
static i32 TC, n, m, dp[N], head[N], adj[N], nxt[N];

static void upd(i32 c) {
  for (i32 i = head[c], u; i; i = nxt[i]) u = adj[i], dp[u] = min(dp[u], dp[c] + 1);
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cin >> n >> m;
    for (i32 i = n, t = 0; i; --i, ++t) dp[i] = t;
    for (i32 i = 0, t = 1, u, v; i < m; ++i) {
      cin >> u >> v;
      if (u > v) swap(u, v);
      adj[t] = u, nxt[t] = head[v], head[v] = t++;
    }
    dp[n + 1] = -1;
    for (i32 i = n; i; --i) dp[i] = min(dp[i + 1] + 1, dp[i]), upd(i);
    for (i32 i = 1; i < n; ++i) cout << (dp[i]) << ' ';
    cout << '\n';
  }
}

