#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, n;
int maximum, t;
pair<int, int> a[u32(2e5) + 1];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    maximum = INT32_MIN;
    cin >> n;
    for (u32 i = 1; i <= n; ++i) cin >> a[i].first;
    for (u32 i = 1; i <= n; ++i) cin >> a[i].second;
    for (u32 i = 1; i <= n; ++i) maximum = max(maximum, a[i].first - a[i].second);
    t = 0;
    for (u32 i = 1; i <= n; ++i) if (a[i].first - a[i].second == maximum) ++t;
    cout << t << '\n';
    for (u32 i = 1; i <= n; ++i) if (a[i].first - a[i].second == maximum) cout << i << ' ';
    cout << '\n';
  }
}

