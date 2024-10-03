#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const i32 N = 200'000;
  i32 st[N << 1], cnt[N << 1], n, q;
  cin >> n >> q;
  fill(st, st + n, INT_MAX);
  fill(cnt + n, cnt + (n << 1), 1);
  for (i32 i = n; i < n << 1; ++i) cin >> st[i];
  for (i32 i = n - 1; i; --i) {
    if (st[i << 1] == st[i << 1 | 1])
      st[i] = st[i << 1], cnt[i] = cnt[i << 1] + cnt[i << 1 | 1];
    else if (st[i << 1] < st[i << 1 | 1])
      st[i] = st[i << 1], cnt[i] = cnt[i << 1];
    else
      st[i] = st[i << 1 | 1], cnt[i] = cnt[i << 1 | 1];
  }
  while (q--) {
    i32 t;
    cin >> t;
    if (t == 1) {
      i32 k, u;
      cin >> k >> u;
      for (st[k += n] = u; k > 1; k >>= 1) {
        if (st[k] == st[k ^ 1]) st[k >> 1] = st[k], cnt[k >> 1] = cnt[k] + cnt[k ^ 1];
        else if (st[k] < st[k ^ 1]) st[k >> 1] = st[k], cnt[k >> 1] = cnt[k];
        else st[k >> 1] = st[k ^ 1], cnt[k >> 1] = cnt[k ^ 1];
      }
    } else {
      i32 l, r, res = INT_MAX, c = 0;
      cin >> l >> r;
      for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
          if (res == st[l]) c += cnt[l];
          else if (res > st[l]) res = st[l], c = cnt[l];
          ++l;
        }
        if (r & 1) {
          --r;
          if (res == st[r]) c += cnt[r];
          else if (res > st[r]) res = st[r], c = cnt[r];
        }
      }
      cout << res << ' ' << c << '\n';
    }
  }
}
