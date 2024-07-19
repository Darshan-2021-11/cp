#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;        using u32 = unsigned int;       using f32 = float;
using i64 = long long;  using u64 = unsigned long long; using f64 = double;
using i128 = __int128;  using u128 = unsigned __int128; using f128 = long double;

static i64 T, n, k, h, low, mid, high, ans, tans;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;
  while (T--) {
    ans = 0;
    cin >> n >> k >> h;
    for (i32 i = 1; i <= n; ++i) {
      if (i >= h) {
        ans += n;
        continue;
      }
      high = n + 1, low = tans = 0;
      while (low <= high) {
        mid = low + high >> 1;
        if (k * i - (k - 1) * mid >= h) tans = mid, low = mid + 1;
        else high = mid - 1;
      }
      ans += tans;
    }
    cout << ans << '\n';
  }
}

