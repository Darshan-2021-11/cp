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

static i32 TC, n, a[100'000], bn, b[100'000], mx, t;
static i64 ans;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    ans = bn = t = 0;
    cin >> n;
    cin >> a[0];
    mx = a[0];
    for (i32 i = 1; i < n; ++i) {
      cin >> a[i];
      if (mx > a[i]) b[bn++] = mx - a[i];
      else mx = a[i];
    }
    sort(b, b + bn);
    for (i32 i = 0; i < bn; ++i)
      ans += (i64)(bn - i + 1) * (b[i] - t), t = b[i];
    cout << ans << '\n';
  }
}
