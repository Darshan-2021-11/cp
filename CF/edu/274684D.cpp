#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 100'000;
  struct node {
    int cnt[40];
  } st[N << 1];
  int a[N], q_cnt[40], n, q, q_t, l, r, idx, v, i, j, ans;
  cin >> n >> q;
  for (i = n; i < n << 1; ++i) {
    cin >> q_t;
    fill_n(st[i].cnt, 40, 0);
    ++st[i].cnt[a[i - n] = q_t - 1];
  }
  for (i = n - 1; i; --i) {
    for (j = 0; j < 40; ++j)
      st[i].cnt[j] = st[i << 1].cnt[j] + st[i << 1 | 1].cnt[j];
  }
  while (q--) {
    cin >> q_t;
    if (q_t == 1) {
      ans = 0;
      fill_n(q_cnt, 40, 0);
      cin >> l >> r;
      --l;
      for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
          for (j = 0; j < 40; ++j) q_cnt[j] += st[l].cnt[j];
          ++l;
        }
        if (r & 1) {
          --r;
          for (j = 0; j < 40; ++j) q_cnt[j] += st[r].cnt[j];
        }
      }
      for (i = 0; i < 40; ++i) ans += q_cnt[i] != 0;
      cout << ans << '\n';
    } else {
      cin >> idx >> v;
      --idx, --v;
      for (--st[idx + n].cnt[a[idx]], a[idx] = v, ++st[idx += n].cnt[v]; idx > 1; idx >>= 1)
        for (j = 0; j < 40; ++j) st[idx >> 1].cnt[j] = st[idx].cnt[j] + st[idx ^ 1].cnt[j];
    }
  }
}
