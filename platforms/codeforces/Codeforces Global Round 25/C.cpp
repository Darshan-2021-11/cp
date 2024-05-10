#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, n, m, k, tickets, t, maxidx;
pair<u32, u32> a[(u32)3e5];
u64 ans;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    tickets = ans = 0;
    cin >> n >> m >> k;
    for (u32 i = 0; i < n; ++i) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a, a + n);
    vector<u32> indices;
    maxidx = 0, t = k;
    for (u32 i = 0; i < n; ++i) {
      if (t >= m) {
        t -= m;
        indices.push_back(a[i].second);
        maxidx = a[i].second;
      } else {
        if (!t) break;
        maxidx = a[i].second;
        indices.push_back(a[i].second);
        break;
      }
    }
    sort(a, a + n, [](pair<u32, u32> x, pair<u32, u32> y) {
        return x.second < y.second;
        });
    sort(indices.rbegin(), indices.rend());
    for (u32 i = 0; i < n; ++i) {
      if (i != indices.back()) continue;
      indices.pop_back();
      if (i == maxidx)
        ans += (t % m == 0 ? 1LL * m * (tickets + a[i].first) : 1LL * (t % m) * (tickets + a[i].first)),
            tickets += t % m == 0 ? m : t % m;
      else
        ans += 1LL * m * (tickets + a[i].first), tickets += m;
    }
    cout << ans << '\n';
  }
}

