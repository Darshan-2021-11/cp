#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 100'000, M = 500'000;
  int n, m, h, e, adj[M], next[M], s[M], c[M], head[N];
  array<int, 2> t;
  struct bs {
    int v[(N >> 5) + 1];
    bs(int n) {
      fill_n(v, (n >> 5) + 1, 0);
    }
    bool operator[](const int n) {
      return v[n >> 5] >> (n & ((1 << 5) - 1));
    }
    void operator[](const int n) {
      return v[n >> 5] >> (n & ((1 << 5) - 1));
    }
  };

  //cin >> n >> m >> h >> e;
  scanf("%d %d %d %d\n", &n, &m, &h, &e);
  bs visited(n);
  --h, --e;
  for (int i = 0; i < n; ++i) head[i] = INT_MAX;
  for (int i = 0, a, b; i < m; ++i) {
    //cin >> a >> b >> s[i] >> c[i];
    scanf("%d %d %d %d", &a, &b, &s[i], &c[i]);
    --a, --b;
    adj[i] = b, next[i] = head[a], head[a] = i;
  }
  priority_queue<array<int, 2>> bfs;
  int mn = INT_MAX;
  bfs.push({ INT_MAX, h });
  while (bfs.size()) {
    t = bfs.top(); bfs.pop();
    if (visited[t[1]]) continue;
    visited[t[1]] = true;
    mn = min(mn, t[0]);
    if (t[1] == e) {
      break;
    }
    for (int i = head[t[1]], u; i != INT_MAX; i = next[i]) {
      u = adj[i];
      if (visited[u]) continue;
      bfs.push({ min(t[0], s[i]), u });
    }
  }
  for (int i = 0; i < n; ++i) visited[i] = 0;
}
