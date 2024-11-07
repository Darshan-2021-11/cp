#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 200'000;
  int64_t TC = 1, n, k, cost[N], cn, profit;
  cin >> TC;
  while (TC--) {
    profit = cn = 0;
    map<int, int64_t> m;
    cin >> n >> k;
    for (int i = 0, b, c; i < k; ++i) {
      cin >> b >> c;
      m[b] += c;
    }
    for (const auto &[i, j]: m) cost[cn++] = j;
    sort(cost, cost + cn, greater<int64_t>());
    for (int i = 0; i < min(cn, n); ++i) profit += cost[i];
    cout << profit << '\n';
  }
}
