#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 100'000;
  int st[N << 1], n, m, m_t, l, r, v, i;
  cin >> n >> m;
  fill_n(st + 1, (n << 1) - 1, 0);
  while (m--) {
    cin >> m_t;
    if (m_t == 1) {
      cin >> l >> r >> v;
      for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) st[l] = max(st[l], v), ++l;
        if (r & 1) --r, st[r] = max(st[r], v);
      }
    } else {
      cin >> i;
      i += n;
      v = 0;
      do {
        v = max(v, st[i]);
        i >>= 1;
      } while (i);
      cout << v << '\n';
    }
  }
}
