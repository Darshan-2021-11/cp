#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = long double;

static i32 TC, n, u, v, mini, a[200'000];
static bool visited[200'000];

void dfs(u32 cur, u32 p, vector<vector<u32>> &adj) {
  for (auto &i: adj[cur]) {
    if (i == p || visited[i]) continue;
    dfs(i, cur, adj);
  }
  if (visited[cur]) return;
  visited[cur] = true;
  cout << cur + 1 << ' ';
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    cin >> n;
    vector<vector<u32>> adj(n);
    mini = 0;
    for (i32 i = 0; i < n; ++i) {
      cin >> a[i], visited[i] = false;
      if (a[i] < a[mini]) mini = i;
    }
    for (i32 i = 1; i < n; ++i) {
      cin >> u >> v;
      --u, --v;
      adj[v].push_back(u);
      adj[u].push_back(v);
    }
    cout << n - 1 << '\n';
    visited[mini] = true;
    dfs(mini, mini, adj);
    cout << '\n';
  }
}

