#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i128 = __int128;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = double;

static const i32 N = 200'001;
static u32 TC, n, curr, u, v, adj[N << 1], nxt[N << 1], a[N], hd[N];
static u64 subcost[N], sum[N];

static void dfs(u32 c, u32 p) {
  sum[c] = a[c];
  u32 node;
  for (u32 i = hd[c]; i; i = nxt[i]) if ((node = adj[i]) != p)
    dfs(node, c),
    subcost[c] += subcost[node] + sum[node], sum[c] += sum[node];
}
static void dfs_rerouting(u32 c, u32 p) {
  u32 node;
  for (u32 i = hd[c]; i; i = nxt[i]) if ((node = adj[i]) != p)
    subcost[node] = subcost[c] + sum[1] - (sum[node] << 1),
    dfs_rerouting(node, c);
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  TC = 1;

  while (TC--) {
    curr = 1;
    cin >> n;
    for (u32 i = 1; i <= n; ++i) cin >> a[i];
    for (u32 i = 1; i < n; ++i)
      cin >> u >> v,
      adj[curr] = v, nxt[curr] = hd[u], hd[u] = curr++,
      adj[curr] = u, nxt[curr] = hd[v], hd[v] = curr++;
    dfs(1, 1);
    dfs_rerouting(1, 1);
    cout << *max_element(subcost + 1, subcost + n + 1) << '\n';
    for (u32 i = 1; i <= n; ++i) subcost[i] = sum[i] = hd[i] = 0;
    cout << sizeof(u32) << '\n';
    cout << sizeof(i32) << '\n';
    cout << sizeof(i128) << '\n';
    cout << sizeof(u64) << '\n';
    cout << sizeof(i64) << '\n';
    cout << sizeof(f32) << '\n';
    cout << sizeof(f64) << '\n';
  }
}
