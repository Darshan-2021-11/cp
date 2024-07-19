#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = long double;

static i64 n, T, i, ll, rr, ans;
static char s[200'000];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> T;
  for (i = 0; i < n; ++i) cin >> s[i];
  static vector<i64> l, r;
  for (i = 0; i < n; ++i) {
    if (s[i] == '0') cin >> l.emplace_back();
    else cin >> r.emplace_back();
  }
  if (!l.size() || !r.size()) {
    cout << 0;
    return 0;
  }
  sort(l.begin(), l.end());
  sort(r.begin(), r.end());
  ll = rr = 0, T <<= 1;
  for (i = 0; i < r.size(); ++i) {
    while (ll < l.size() && r[i] + T >= l[ll]) ++ll;
    if (ll == l.size()) break;
    while (rr < l.size() && r[i] > l[rr]) ++rr;
    ans += ll - rr;
  }
  for (; i < r.size(); ++i) {
    while (rr < l.size() && r[i] > l[rr]) ++rr;
    if (rr == l.size()) break;
    ans += ll - rr;
  }
  cout << ans;
}
