#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 100'001;
static i32 n, head[N], adj[N << 1], nxt[N << 1], prb[N];
static bitset<N> bp, winner;

static void dfs(i32 c, i32 p) {
  for (i32 i = head[c], u; i; i = nxt[i]) if ((u = adj[i]) != p) {
    dfs(u, c);
    if (prb[u]) prb[c] += prb[u];
    else prb[c] += winner[u] = bp[(i + 1) >> 1];
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n;
  for (i32 i = 1, t = 1, u, v, k; i < n; ++i) {
    cin >> u >> v >> k;
    adj[t] = v, nxt[t] = head[u], head[u] = t++;
    adj[t] = u, nxt[t] = head[v], head[v] = t++;
    bp[i] = k - 1;
  }
  dfs(1, 1);
  cout << prb[1] << '\n';
  for (i32 i = 1; i <= n; ++i) if (winner[i]) cout << i << ' ';
}
