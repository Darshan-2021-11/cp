#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 200'001;
  int a[N], st[N << 1], n, q, q_t;
  cin >> n;
  if (n == 1) {
    cin >> a[0];
    cin >> q;
    while (q--) {
      cin >> q_t;
      if (q_t == 1) {
        int i, p;
        cin >> i >> p;
        a[0] = p;
      } else {
        int i, t;
        cin >> i >> t;
        cout << 1 << '\n';
      }
    }
    return 0;
  }
  for (int i = 0; i < n; ++i) cin >> a[i];
  a[n] = a[n - 1];
  for (int i = n; i < n << 1; ++i) st[i] = abs(a[i - n] - a[i + 1 - n]);
  for (int i = n - 1; i; --i) st[i] = max(st[i << 1], st[i << 1 | 1]);
  cin >> q;
  while (q--) {
    cin >> q_t;
    if (q_t == 1) {
      int i, p;
      cin >> i >> p; --i;
      a[i] = p;
      if (!i) {
        i += n;
        for (st[i] = abs(a[0] - a[1]); i >>= 1;) st[i] = max(st[i << 1], st[i << 1 | 1]);
      } else {
        if (i == n - 1) a[n] = p;
        int ti = i - 1;
        st[i + n] = abs(a[i] - a[i + 1]);
        st[ti + n] = abs(a[ti] - a[i]);
        i += n;
        ti += n;
        for (; i >>= 1;) st[i] = max(st[i << 1], st[i << 1 | 1]);
        for (; ti >>= 1;) st[ti] = max(st[ti << 1], st[ti << 1 | 1]);
      }
    } else {
      int l, t, idx = -1, tmp[20], tmpn = 0;
      cin >> l >> t; --l;
      l += n;
      for (int r = (n << 1) - 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
          if (st[l] > t) { idx = l; break; }
          l++;
        }
        if (r & 1) {
          --r;
          if (st[r] > t) { tmp[tmpn++] = r; }
        }
      }
      if (idx == -1) {
        while (tmpn--) if (st[tmp[tmpn]] > t) { idx = tmp[tmpn]; break; }
      }
      if (idx == -1) cout << n << '\n';
      else {
        while (idx < n) {
          idx <<= 1;
          if (st[idx] <= t) ++idx;
        }
        cout << idx - n + 1 << '\n';
      }
    }
  }
}
