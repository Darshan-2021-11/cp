#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 100'001;
static i32 TC, n, a[N], b[N], c[N];
static i64 ans;
static map<i32, i32> m;
static map<i32, i32>::iterator it;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    ans = 0;
    cin >> n;
    for (i32 i = 0; i < n; ++i) {
      cin >> a[i];
      if ((it = m.find(a[i])) == m.end()) m[a[i]] = i, b[i] = 1;
      else b[it->second] = 0, b[i] = 1, m[a[i]] = i;
    }
    m.clear();
    for (i32 i = n - 1, t = n; ~i; --i) {
      c[i] = n - 1 - i - m.size();
      ++m[a[i]];
      if (b[i]) t = i, b[i] = i;
      else b[i] = t;
    }
    m.clear();
    for (i32 i = 0; i < n; ++i) {
      if (m.find(a[i]) != m.end()) continue;
      ans += n - b[i] - c[b[i]];
      ++m[a[i]];
    }
    cout << ans << '\n';
    m.clear();
  }
}
