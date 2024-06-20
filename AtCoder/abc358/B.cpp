#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = long double;

static i32 n, a, b[1'000'000], ans;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> a;
  for (i32 i = 0; i < n; ++i) cin >> b[i];
  ans = b[0] + a;
  cout << ans << '\n';
  for (i32 i = 1; i < n; ++i) {
    if (b[i - 1] + a <= b[i]) ans = b[i] + a;
    else ans += a;
    cout << ans << '\n';
  }

}

