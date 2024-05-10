#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, n, k, l, r, t, tl, tr;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;
  /* MAP IMPLEMENTATION
  map<u32, u32> values;

  while (T--) {
    l = r = tl = tr = UINT32_MAX;
    cin >> n >> k;
    --k;
    for (u32 i = 0; i < n; ++i) {
      cin >> t;
      ++values[t];
    }
    for (auto &i: values) {
      if (i.second > k) {
        if (tr == UINT32_MAX || tr + 1 != i.first) {
          tl = tr = i.first;
          if (l == UINT32_MAX) l = r = tl;
        } else {
          tr = i.first;
          if (tr - tl >= r - l) l = tl, r = tr;
        }
      } else tl = tr = UINT32_MAX;
    }
    if (l != UINT32_MAX)
      cout << l << ' ' << r << '\n';
    else
      cout << -1 << '\n';
    values.clear();
  }
  */
  /* TWO POINTERS IMPLEMENTATION */
  while (T--) {
    l = r = tl = tr = UINT32_MAX;
    cin >> n >> k;
    --k;
    vector<u32> a(n), cnt(1, 1);
    for (u32 i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    t = 0;
    for (u32 i = 1; i < n; ++i)
      if (a[i] != a[i - 1]) a[++t] = a[i], cnt.push_back(1);
      else ++cnt.back();
    for (u32 i = 0; i <= t; ++i) {
      if (cnt[i] > k) {
        if (tr == UINT32_MAX || tr + 1 != a[i]) {
          tl = tr = a[i];
          if (l == UINT32_MAX) l = r = tl;
        } else {
          tr = a[i];
          if (tr - tl >= r - l) l = tl, r = tr;
        }
      } else tl = tr = UINT32_MAX;
    }
    if (l != UINT32_MAX)
      cout << l << ' ' << r << '\n';
    else
      cout << -1 << '\n';
  }
}

