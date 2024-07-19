#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i32 T, n, nxt[N << 1], adj[N << 1], head[N], a[N];

static i32 dfs(i32 c, i32 p) {
  i32 idx{}, ans{}, u;
  for (i32 i = head[c]; i; i = nxt[i]) if (adj[i] == p) { idx = i; break; }
  for (i32 i = head[c]; i; i = nxt[i]) if ((u = adj[i]) != p)
    ans = max(ans, dfs(u, c) + (i < idx));
  return ans;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;
  while (T--) {
    cin >> n;
    for (i32 i = 1, t = 1; i < n; ++i) {
      i32 u, v;
      cin >> u >> v;
      adj[t] = u, nxt[t] = head[v], head[v] = t++;
      adj[t] = v, nxt[t] = head[u], head[u] = t++;
    }
    cout << dfs(1, 1) + 1 << '\n';
    for (i32 i = 1; i <= n; ++i) head[i] = a[i] = 0;
  }
}
