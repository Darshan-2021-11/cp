#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const u32 N = 100'001;
static u32 T, n, x, a;
static vector<u32> f;
static bitset<50'001> mp;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;
  mp[1] = 1;
  while (T--) {
    f.push_back(1);
    cin >> n >> x;
    u32 i;
    for (i = 2; i * i < x; ++i) {
      if (x % i) continue;
      f.push_back(x / i);
      f.push_back(x / f.back());
    }
    if (i * i == x) f.push_back(i);
    sort(f.begin(), f.end());
    u32 ans = 1;
    for (i = 0; i < n; ++i) {
      cin >> a;
      if (x % a) continue;
      for (u32 j = f.size() - 1, t; ~j; --j) {
        if (!mp[f[j]]) continue;
        t = a * f[j];
        if (t == x) {
          ++ans;
          for (u32 k = 1; k < f.size(); ++k) mp[f[k]] = 0;
          break;
        }
        if (!binary_search(f.begin(), f.end(), t)) continue;
        mp[t] = 1;
      }
      mp[a] = 1;
    }
    for (i = 1; i < f.size(); ++i) mp[f[i]] = 0;
    f.clear();
    cout << ans << '\n';
  }
}
