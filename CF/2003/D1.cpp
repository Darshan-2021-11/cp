#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 200'001;
  i32 TC = 1, n, m, a[N], mex[N];
  i64 ans;
  bitset<N> bs;
  cin >> TC;
  while (TC--) {
    cin >> n >> m;
    for (i32 i = 0, t; i < n; ++i) {
      cin >> t;
      for (i32 j = 0; j < t; ++j) {
        cin >> a[j];
        if (a[j] < N) bs[a[j]] = true;
      }
      i32 x = 0; while (bs[x]) ++x;
      mex[i] = x;
      for (i32 j = 0; j < t; ++j) bs[a[j]] = false;
    }
    sort(mex, mex + n);
    n = unique(mex, mex + n) - mex;
    ans = m;
    ans = (ans * (ans + 1)) >> 1;
    for (i32 i = 0, e; i < n; ++i) cout << mex[i] << ' ';
    cout << '\n';
    for (i32 i = 0, e; i < n; ++i) {
      if (mex[i] > m) break;
      e = i + 1;
      while (e < n && mex[e] + 1 == mex[e - 1]) ++e;
      cout << i << ',' << e << ' ';
      i64 t = e - i + 1;
      ans += (t * (t + 1)) >> 1;
      i = e;
    }
    cout << ans << '\n';
    cout << '\n';
  }
}
