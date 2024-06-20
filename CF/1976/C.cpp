#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u64 psum, tsum;
static u32 TC, n, m, a[(u32)2e5], b[(u32)2e5], pn, tn, p[(u32)2e5], t[(u32)2e5];
static bool pb[(u32)2e5], tb[(u32)2e5], pi, ti;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    psum = tsum = pn = tn = 0;
    cin >> n >> m;
    for (u32 i = 0; i < n + m + 1; ++i) pb[i] = tb[i] = false, cin >> a[i];
    for (u32 i = 0; i < n + m + 1; ++i) cin >> b[i];
    for (u32 i = 0; i < n + m + 1; ++i) {
      pi = ti = false;
      if (pn <= n && (a[i] > b[i] || tn >= m)) p[pn] = i, psum += a[i], pb[i] = true, pi = true;
      if (tn <= m && (b[i] > a[i] || pn >= n)) t[tn] = i, tsum += b[i], tb[i] = true, ti = true;
      pn += pi;
      tn += ti;
    }
    if (!n) {
      for (u32 i = 0; i < n + m + 1; ++i) {
        if (tb[i]) cout << tsum - b[i] << ' ';
        else cout << tsum - b[t[tn - 1]] << ' ';
      }
      cout << '\n';
      continue;
    } else if (!m) {
      for (u32 i = 0; i < n + m + 1; ++i) {
        if (pb[i]) cout << psum - a[i] << ' ';
        else cout << psum - a[p[pn - 1]] << ' ';
      }
      cout << '\n';
      continue;
    }
//    for (u32 i = 0; i < tn; ++i) cout << t[i] << ' '; cout << ';';
//    for (u32 i = 0; i < pn; ++i) cout << p[i] << ' '; cout << ';';
    for (u32 i = 0; i < n + m + 1; ++i) {
      if (pb[i] && tb[i]) {
        cout << psum + tsum - a[i] - b[i] << ' ';
      } else if (pb[i]) {
        if (tb[p[pn - 1]])
          cout << psum + tsum - a[i] - b[p[pn - 1]] << ' ';
        else
          cout << psum + tsum - a[i] - b[t[tn - 1]] << ' ';
      } else {
        if (pb[t[tn - 1]])
          cout << psum + tsum - b[i] - a[t[tn - 1]] << ' ';
        else
          cout << psum + tsum - b[i] - a[p[pn - 1]] << ' ';
      }
    }
    cout << '\n';
  }
}

