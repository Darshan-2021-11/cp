#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = long double;

static i32 TC, n, t, a[500'000], mn, mx, cmx;
vector<i32> mns, mxs;
static bool yes, found;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    t = found = 0;
    yes = true;
    cin >> n;
    for (i32 i = 0; i < n; ++i) cin >> a[i];
    cmx = a[0];
    for (i32 i = 1; i < n; ++i) {
      if (a[i] < cmx) mns.push_back(cmx - a[i]);
      else cmx = a[i];
      if (a[i] < a[i - 1]) {
        if (!found) found = true;
        else { yes = false; break; }
        if (t != 0) {
          mxs.push_back(t);
          t = 0;
        }
        mns.push_back(a[i - 1] - a[i]);
        if (i == n - 1 || a[i + 1] < a[i]) continue;
        t = max(t, a[i + 1] - a[i]);
      } else {
        found = false;
        if (i == n - 1 || a[i + 1] < a[i]) continue;
        t = max(t, a[i + 1] - a[i]);
      }
    }
    mn = mns.size() ? *max_element(mns.begin(), mns.end()) : 0;
    mx = mxs.size() ? *min_element(mxs.begin(), mxs.end()) : n;
    if (is_sorted(a, a + n)) mx = n;
    yes &= mn <= mx;
    //cout << mn << ' ' << mx << ' ';
    if (yes) {
      cout << (((u64)(mx + mn) * (mx - mn + 1)) >> 1) << '\n';
    } else {
      cout << 0 << '\n';
    }
    mns.clear();
    mxs.clear();
  }
}

