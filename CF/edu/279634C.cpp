#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 100'000;
  int st[N << 1], d[N], n, m, m_t, l, r, v, i;
  cin >> n >> m;
  const int h = (sizeof(int) << 3) - __builtin_clz(n);
  fill_n(st, n << 1, 0);
  fill_n(d, n, INT_MAX);
  const auto push = [&](int x) {
    for (int s = h, idx; s; --s) {
      if (d[idx = x >> s] != INT_MAX) {
        st[idx << 1] = st[idx << 1 | 1] = d[idx];
        if ((idx << 1) < n) d[idx << 1] = d[idx];
        if ((idx << 1 | 1) < n) d[idx << 1 | 1] = d[idx];
        d[idx] = INT_MAX;
      }
    }
  };
  while (m--) {
    cin >> m_t;
    if (m_t == 1) {
      cin >> l >> r >> v;
      l += n, r += n;
      push(l), push(r - 1);
      for (; l < r; l >>= 1, r >>= 1) {
        if (l & 1) { st[l] = v; if (l < n) d[l] = v; ++l; }
        if (r & 1) { st[--r] = v; if (r < n) d[r] = v; }
      }
    } else {
      cin >> i;
      i += n;
      push(i);
      cout << st[i] << '\n';
    }
  }
}
