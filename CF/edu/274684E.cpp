#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 100'000;
  int st[N << 1], n, m, m_t, idx, h, l, r, p, ans;
  cin >> n >> m;
  fill_n(st + 1, (n << 1) - 1, INT_MAX);
  while (m--) {
    cin >> m_t;
    if (m_t == 1) {
      cin >> idx >> h;
      for (st[idx += n] = h; idx >>= 1;) st[idx] = min(st[idx << 1], st[idx << 1 | 1]);
    } else {
      ans = 0;
      cin >> l >> r >> p;
      l += n, r += n;
      ++p;
      while (true) {
        for (idx = -1; l < r; l >>= 1, r >>= 1) {
          if (l & 1) { if (p > st[l]) { idx = l; break; } ++l; }
          if (r & 1) { --r; if (p > st[r]) { idx = r++; break; } }
        }
        if (idx == -1) break;
        while (idx < n) {
          idx <<= 1;
          idx += st[idx] >= p;
        }
        for (st[idx] = INT_MAX, ++ans; idx >>= 1;) st[idx] = min(st[idx << 1], st[idx << 1 | 1]);
      }
      cout << ans << '\n';
    }
  }
}
