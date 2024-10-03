#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 8;
  uint64_t g = 0, h = 0, t = 1;
  int cost[N][N], p[N], n, mg, mh, u, v;
  cin >> n;
  cin >> mg;
  for (int i = 0; i < mg; ++i)
    cin >> u >> v, --u, --v, g |= t << ((u << 3) + v), g |= t << ((v << 3) + u);
  cin >> mh;
  for (int i = 0; i < mh; ++i)
    cin >> u >> v, --u, --v, h |= t << ((u << 3) + v), h |= t << ((v << 3) + u);
  for (int i = 0; i < n; ++i) {
    cost[i][i] = 0;
    for (int j = i + 1; j < n; ++j)
      cin >> cost[i][j], cost[j][i] = cost[i][j];
  }
  iota(p, p + n, 0);
  u = INT_MAX;
  do {
    v = 0;
    for (int i = n - 1; i; --i) {
      for (int j = 0; j < i; ++j) {
        if (
            ((g & (t << ((j << 3) + i))) != 0) ^
            ((h & (t << ((p[j] << 3) + p[i]))) != 0)
            ) v += cost[p[i]][p[j]];
      }
    }
    u = min(v, u);
  } while (next_permutation(p, p + n));
  cout << u;
}
