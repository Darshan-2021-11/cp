#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int inv(int a) {
  return a <= 1 ? a : MOD - (long long)(MOD/a) * inv(MOD % a) % MOD;
}
vector<int> graph[200001];
using ll = long long;
ll n, dp[200001], ans[200001];
void dfs1(int node = 1, int parent = 0, ll depth = 0) {
  ans[1] += depth;
  dp[node] = 1;
  for (int i : graph[node])
    if (i != parent) {
      dfs1(i, node, depth + 1);
      dp[node] += dp[i];
    }
}

void dfs2(int node = 1, int parent = 0) {
  for (int i : graph[node])
    if (i != parent) {
      ans[i] = ans[node] + n - 2 * dp[i];
      dfs2(i, node);
    }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  dfs1();
  dfs2();
  ll sum = 0;
  for (int i = 1; i <= n; i++) sum += ans[i];
  ll res = sum;
  res %= MOD;
  res *= inv((n * (n + 1)) % MOD);
  res %= MOD;
  cout << res << '\n';
  return 0;
}
