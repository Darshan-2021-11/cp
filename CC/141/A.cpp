#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;        using u32 = unsigned int;       using f32 = float;
using i64 = long long;  using u64 = unsigned long long; using f64 = double;
using i128 = __int128;  using u128 = unsigned __int128; using f128 = long double;

static i32 T, n, a[200'000];
static i64 ans;
static map<i32, i32> mp;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;
  while (T--) {
    ans = LLONG_MAX;
    cin >> n;
    mp[1] = 0;
    for (i32 i = 0; i < n; ++i) {
      cin >> a[i];
      ++mp[a[i]];
    }
    for (const auto &i: mp) {
      ans = min(ans, (i64)(n - i.second) * i.first);
    }
    cout << ans << '\n';
    mp.clear();
  }
}

