#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

const int N = 200'000, sign[] = { 1, -1 };
int adj[N << 1], head[N], nxt[N << 1], w[N], n, m;
int64_t val[N];

void dfs(int c, int64_t v) {
  val[c] = v;
  for (int i = head[c], u; i != INT_MAX; i = nxt[i]) {
    u = adj[i];
    if (val[u] != LLONG_MAX) continue;
    dfs(u, v + (w[i >> 1] * sign[i & 1]));
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) head[i] = INT_MAX, val[i] = LLONG_MAX;
  for (int i = 0, u, v; i < m; ++i) {
    cin >> u >> v >> w[i];
    --u, --v;
    adj[i << 1] = v, nxt[i << 1] = head[u], head[u] = i << 1;
    adj[i << 1 | 1] = u, nxt[i << 1 | 1] = head[v], head[v] = i << 1 | 1;
  }
  for (int i = 0; i < n; ++i) if (val[i] == LLONG_MAX) dfs(i, 0);
  for (int i = 0; i < n; ++i) cout << val[i] << ' ';
}
