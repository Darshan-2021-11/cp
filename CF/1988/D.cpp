#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i64 N = 300'001;
static i64 TC, d[N], ans;
static i32 n, t, hd[N], nxt[N << 1], ad[N << 1];
static pair<i64, i32> dp[N];

static void link(i32 u, i32 v) {
  ad[t] = v, nxt[t] = hd[u], hd[u] = t++;
}

static void dfs(i32 c, i32 p) {
  i32 u;
  for (i32 i = hd[c]; i; i = nxt[i]) if ((u = ad[i]) != p) {
    dfs(u, c);
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cin >> n;
    for (i32 i = 1; i <= n; ++i) cin >> d[i];
    t = 1;
    for (i32 i = 1, u, v; i < n; ++i) {
      cin >> u >> v; link(u, v); link(v, u);
    }
    dfs(1, 0);
    for (i32 i = 1; i <= n; ++i) hd[i] = 0;
  }
}
