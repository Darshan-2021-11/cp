#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i32 n, k, head[N], child[N], depth[N], adj[N << 1], nxt[N << 1];
static bitset<N> visited;

static void dfs(i32 c, i32 p, i32 d) {
  depth[c] = d;
  for (i32 i = head[c], u; i; i = nxt[i]) if ((u = adj[i]) != p) {
    dfs(u, c, d + 1);
    child[c] += 1 + child[u];
  }
}

static i64 bfs(i32 s) {
  priority_queue<pair<i32, i32>, vector<pair<i32, i32>>, less<pair<i32, i32>>> pq;
  i64 ans{};
  i32 tk = 1;
  pq.push({ child[s] - depth[s], s });
  while (tk <= k && pq.size()) {
    const auto [inc, c] = pq.top();
    pq.pop();
    if (visited[c]) continue;
    visited[c] = true;
    ans += inc;
    if (++tk > k) break;
    for (i32 i = head[c], u; i; i = nxt[i]) {
      u = adj[i];
      if (visited[u]) continue;
      pq.push({ child[u] - depth[u], u });
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> k;
  k = n - k;
  for (i32 i = 1, t = 1; i < n; ++i) {
    i64 u, v;
    cin >> u >> v;
    adj[t] = v, nxt[t] = head[u], head[u] = t++;
    adj[t] = u, nxt[t] = head[v], head[v] = t++;
  }
  dfs(1, 1, 0);
  cout << bfs(1);
}
