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

static i64 TC, n, l, r, lft, a[100'000], sum, ans;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    ans = sum = lft = 0;
    cin >> n >> l >> r;
    for (i32 i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
      if (sum >= l) {
        if (sum <= r) ++ans, sum = 0, lft = i + 1;
        else {
          while (sum > r) sum -= a[lft++];
          if (sum >= l) ++ans, sum = 0, lft = i + 1;
        }
      }
    }
    cout << ans << '\n';
  }
}

