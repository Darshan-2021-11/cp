#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int T = 1, n, t, uni[(int)2e5];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    map<int, vector<ll>> univ;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> t;
      uni[i] = t;
    }
    for (int i = 0; i < n; ++i) {
      cin >> univ[uni[i]].emplace_back();
    }
    vector<ll> ans(n);
    for (auto &[x, y]: univ) {
      sort(y.begin(), y.end(), greater<ll>());
      vector<ll> tv(y.size());
      for (int i = 1; i < y.size(); ++i)
        y[i] += y[i - 1];
      /*
      cout << x << ':' << ' ';
      for (auto &i: y) cout << i << ' ';
      cout << '\n';
      */
      for (int i = 1; i <= n; ++i) {
        if (y.size() < i) break;
        ans[i - 1] += y[(y.size() / i) * i - 1];
      }
    }
    for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
    cout << '\n';
  }
}

