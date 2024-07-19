#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static i64 T, n;

i32 diglen(i32 nx) {
  i32 digits{};
  while (nx) { ++digits, nx /= 10; }
  return digits;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;
  while (T--) {
    cin >> n;
    string ns = to_string(n);
    reverse(ns.begin(), ns.end());
    string nsm = "$";
    vector<pair<i32, i32>> ans;
    for (i32 a = 1; a <= 10'000; ++a) {
      nsm += ns;
    }
    for (i32 a = 1; a <= 10'000; ++a) {
      i32 low = 1, high = 10'001, mid, bl = high, bh = 0;
      while (low <= high) {
       mid = (low + high) >> 1;
        if (ns.size() * a >= mid + diglen(n * a - mid)) bl = mid, low = mid + 1;
        else high = mid - 1;
      }
      low = 1, high = 10'001;
      while (low <= high) {
        mid = (low + high) >> 1;
        if (ns.size() * a > mid) bh = mid, low = mid + 1;
        else high = mid - 1;
      }
      if (bl == 10'001) continue;
      if (bl > bh) swap(bl, bh);
      bh = min(10'000, bh);
      for (i32 b = bl, t; b <= bh; ++b) {
        t = 0;
        for (i32 k = ns.size() * a; b < k; --k) {
          t = 10 * t + (nsm[k] - '0');
        }
        if (t == 0 || b <= 0 || b > 10'000) continue;
        if (t == n * a - b) {
          ans.emplace_back(a, b);
        }
      }
    }
    cout << ans.size() << '\n';
    for (const auto &[i, j]: ans) {
      cout << i << ' ' << j << '\n';
    }
  }
}
