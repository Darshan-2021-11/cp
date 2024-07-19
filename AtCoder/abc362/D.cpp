#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i64 N = 200'001;
static i64 n, m, a[N], head[N], adj[N << 1], nxt[N << 1], w[N << 1], res[N];
static bitset<N> visited;

static void bfs(i64 c) {
  priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<pair<i64, i64>>> pq;
  pq.push({ 0, c });
  while (pq.size()) {
    i64 u = pq.top().second, cost = pq.top().first + a[u], v;
    pq.pop();
    if (visited[u]) continue;
    visited[u] = true;
    for (i32 i = head[u]; i; i = nxt[i]) {
      v = adj[i];
      if (visited[v]) continue;
      res[v] = min(cost + w[i], res[v]);
      pq.push({ res[v], v });
    }
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> m;
  for (i32 i = 1; i <= n; ++i) {
    cin >> a[i];
    res[i] = LLONG_MAX;
  }
  res[1] = 0;
  for (i32 i = 1, t = 1; i <= m; ++i) {
    i64 u, v, b;
    cin >> u >> v >> b;
    adj[t] = v, nxt[t] = head[u], w[t] = b, head[u] = t++;
    adj[t] = u, nxt[t] = head[v], w[t] = b, head[v] = t++;
  }
  bfs(1);
  for (i32 i = 2; i <= n; ++i) cout << res[i] + a[i] << ' ';
}
