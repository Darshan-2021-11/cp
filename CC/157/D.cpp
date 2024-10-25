#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 300'000;
  int64_t ans, sum, t;
  int TC = 1, n, a[N], cnt[4], i, p;
  cin >> TC;
  while (TC--) {
    ans = 0;
    fill_n(cnt + 1, 3, 0);
    cin >> n;
    // subarrays containing 1, 2, 3 individually only
    for (i = 0, t = 0, p = INT_MAX; i < n; ++i) {
      cin >> a[i];
      if (p != a[i]) ans += p != 2 ? (t * (t + 1)) >> 1 : 0LL, p = a[i], t = 1;
      else ++t;
    }
    ans += p != 2 ? (t * (t + 1)) >> 1 : 0LL;
    //cout << ans << ' ';
    map<int, map<int, int>> m;
    pair<int, int> d { 0, 0 };
    ++m[d.first][0];
    for (i = 0; i < n; ++i) {
      ++cnt[a[i]];
      d.first = cnt[3] - cnt[1], d.second = cnt[3] - cnt[2];
      //cout << '{' << cnt[1] << ',' << cnt[2] << ',' << cnt[3] << '}' << ':' << d.first << ',' << d.second << ' ';
      ++m[d.first][d.second];
    }
    for (const auto &[u, v]: m) {
      sum = 0;
      //cout << u << "->";
      for (const auto &[w, x]: v) sum += x;
        //cout << w << ':' << x << ',';
      for (const auto &[w, x]: v) {
        sum -= x;
        ans += x * sum;
        //cout << '!' << ans << ',';
      }
    }
    cout << ans << '\n';
  }
}
