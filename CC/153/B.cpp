#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 200'001;
  int TC = 1, n;
  int64_t ans;
  cin >> TC;
  while (TC--) {
    ans = 0;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1, u, v; i < n; ++i) {
      cin >> u >> v;
      adj[--u].push_back(--v);
      adj[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
      if (adj[i].size() > 1) ans += 2;
      else ans += 3;
    }
    cout << ans << '\n';
  }
}
