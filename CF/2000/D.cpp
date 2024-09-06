#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i32 TC, n;
static i64 a[N];
static i64 ans;
static char s[N];
static vector<i32> li, ri;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    ans = 0;
    cin >> n;
    for (i32 i = 0; i < n; ++i) cin >> a[i];
    partial_sum(a, a + n, a);
    for (i32 i = 0; i < n; ++i) {
      cin >> s[i];
      if (s[i] == 'L') li.push_back(i);
      else ri.push_back(i);
    }
    for (i32 i = 0, j = ri.size() - 1; i < (i32)li.size(); ++i, --j) {
      if (j < 0) break;
      const i32 l = li[i], r = ri[j];
      if (l > r) continue;
      if (l) ans += a[r] - a[l - 1];
      else ans += a[r];
    }
    cout << ans << '\n';
    li.clear(), ri.clear();
  }
}
