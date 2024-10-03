#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 200'000;
  int64_t ans, sum;
  int TC = 1, n, a[N];
  cin >> TC;
  while (TC--) {
    ans = sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int prev = a[0] - 1;
    vector<pair<int, int>> v(n - 1);
    for (int i = 1; i < n; ++i) {
      v.emplace_back(a[i] - prev, a[i] + prev);
      prev = a[i] - 1;
    }
    int l = 0, r = 0;
    set<int> right;
    right.insert(0);
    for (int i = 0; i < v.size(); ++i) {
      if (l >= v[i].first && r <= v[i].second) l = v[i].first, r = v[i].second;
      else if (r >= v[i].first) r = v[i].second, l = min(v[i].first, l);
      else {
        assert(v[i].first > r);
        l = *right.lower_bound(l);
        ans += r - l + (l != 0);
        right.insert(r);
        l = v[i].first, r = v[i].second;
      }
    }
    ans += r - l + (l != 0);
    cout << ans << '\n';
  }
}
