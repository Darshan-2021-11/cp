#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 const MAX = 1e5;
static u32 TC, n, k, u, v, t, mid, cuts, mx, adj[(MAX << 1) + 1], nxt[(MAX << 1) + 1], hd[MAX + 1];

u32 dfs(u32 node, u32 parent) {
  u32 nodes = 1;
  for (u32 i = hd[node]; i; i = nxt[i]) if (adj[i] - parent) nodes += dfs(adj[i], node);
  if (node != 1 && nodes >= mid) {
    ++cuts;
    return 0;
  }
  return nodes;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    cin >> n >> k;
    for (u32 i = 1, t = 1; i < n; ++i)
      cin >> u >> v,
      adj[t] = v, nxt[t] = hd[u], hd[u] = t++,
      adj[t] = u, nxt[t] = hd[v], hd[v] = t++;
    u = 1, v = n + 1;
    while (u <= v) {
      mid = u + v >> 1, cuts = 0;
      t = dfs(1, 1);
      if (cuts > k || (cuts == k && mid <= t)) {
        mx = max(mx, mid);
        u = mid + 1;
      } else v = mid - 1;
    }
    cout << mx << endl;
    mx = 0;
    fill_n(hd + 1, n + 1, 0);
  }
}
