#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = long double;

static i32 const MOD = 998244353;
static i32 TC, n, idx, a[200000];
static i64 tans, ans, c, nsum, psum, mxc, t;

int count_mxc(i64 val, i32 index) {
  if (index == n) return val == mxc;
  val += a[index++];
  return count_mxc(abs(val), index) + count_mxc(val, index);
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    nsum = psum = mxc = c = 0, ans = 1;
    cin >> n;
    for (i32 i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] < 0) nsum += a[i];
      else psum += a[i];
    }
    c = 0;
    for (i32 i = 0; i < n; ++i) {
      c += a[i];
      if (a[i] > 0) psum -= a[i];
      else nsum -= a[i];
      if ((t = abs(c) + psum + nsum) > mxc) {
        idx = i;
        mxc = t;
      }
    }
    cout << mxc << ',' << idx << ' ' << count_mxc(0, 0) << '\n';
  }
}
