#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, a[u32(1e5)], b[u32(1e5)], n, m, d, t, ans, pre, cur;
bool isGood;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    isGood = false;
    cin >> n >> m >> d;
    ++d;
    for (u32 i = 0; i < n; ++i) { cin >> t; a[t] = i; }

    cin >> b[0];
    for (u32 i = 1; i < m; ++i) {
      cin >> b[i];
      if (a[b[i - 1]] > a[b[i]] || a[b[i]] >= a[b[i - 1]] + d) isGood = true;
    }

    if (isGood) {
      cout << 0 << '\n';
      continue;
    }
    ans = UINT32_MAX, pre = a[b[0]];
    for (u32 i = 1; i < m; ++i) {
      cur = a[b[i]];
      ans = min(ans, cur - pre);
      if (n > d) ans = min(ans, d + pre - cur);
      pre = cur;
    }
    cout << ans << '\n';
  }
}

