#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 100'000;
  struct node {
    int64_t inv;
    int cnt[40];
  } st[N << 1];
  int64_t inv, sum;
  int a[N], q_cnt[40], r_t[18], r_tn, n, q, q_t, l, r, idx, v, i, j;
  cin >> n >> q;
  for (i = n; i < n << 1; ++i) {
    cin >> q_t; --q_t;
    st[i].inv = 0;
    fill_n(st[i].cnt, 40, 0);
    ++st[i].cnt[a[i - n] = q_t];
  }
  for (i = n - 1; i; --i) {
    st[i].inv = st[i << 1].inv + st[i << 1 | 1].inv;
    for (sum = 0, j = 0; j < 40; ++j) sum += st[i << 1].cnt[j];
    for (j = 0; j < 40; ++j) {
      sum -= st[i << 1].cnt[j];
      st[i].inv += sum * st[i << 1 | 1].cnt[j];
      st[i].cnt[j] = st[i << 1].cnt[j] + st[i << 1 | 1].cnt[j];
    }
  }
  while (q--) {
    cin >> q_t;
    if (q_t == 1) {
      fill_n(q_cnt, 40, 0);
      cin >> l >> r;
      --l;
      for (l += n, r += n, inv = r_tn = 0; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
          inv += st[l].inv, sum = 0;
          for (j = 0; j < 40; ++j) sum += q_cnt[j];
          for (j = 0; j < 40; ++j) {
            sum -= q_cnt[j];
            inv += sum * st[l].cnt[j];
            q_cnt[j] += st[l].cnt[j];
          }
          ++l;
        }
        if (r & 1) r_t[r_tn++] = --r;
      }
      while (r_tn--) {
        inv += st[r_t[r_tn]].inv;
        for (sum = j = 0; j < 40; ++j) sum += q_cnt[j];
        for (j = 0; j < 40; ++j) {
          sum -= q_cnt[j];
          inv += sum * st[r_t[r_tn]].cnt[j];
          q_cnt[j] += st[r_t[r_tn]].cnt[j];
        }
      }
      cout << inv << '\n';
    } else {
      cin >> idx >> v;
      --idx, --v;
      for (--st[idx + n].cnt[a[idx]], a[idx] = v, ++st[idx += n].cnt[v]; idx > 1; idx >>= 1) {
        l = idx, r = idx ^ 1;
        if (l > r) swap(l, r);
        st[idx >> 1].inv = st[l].inv + st[r].inv;
        for (sum = j = 0; j < 40; ++j) sum += st[l].cnt[j];
        for (j = 0; j < 40; ++j) {
          sum -= st[l].cnt[j];
          st[idx >> 1].inv += sum * st[r].cnt[j];
          st[idx >> 1].cnt[j] = st[l].cnt[j] + st[r].cnt[j];
        }
      }
    }
  }
}
