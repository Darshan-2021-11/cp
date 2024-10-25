#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 200'000;
  int TC = 1, n, adj[N << 1], next[N << 1], head[N];
  cin >> TC;
  while (TC--) {
    cin >> n;
    for (int i = 0; i < n; ++i) head[i] = -1;
    for (int i = 0, u, v; i < (n - 1) << 1;) {
      cin >> u >> v;
      adj[i] = u, next[i] = head[v], head[v] = i++;
      adj[i] = v, next[i] = head[u], head[u] = i++;
    }
  }
}
