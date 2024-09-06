#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static i64 TC, a[2], b[2], ans;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    ans = 0;
    for (i32 i = 0; i < 2; ++i) cin >> a[i];
    for (i32 i = 0; i < 2; ++i) cin >> b[i];
    for (i32 i = 0; i < 2; ++i) {
      for (i32 j = 0; j < 2; ++j) {
        i32 w1 = 0, w2 = 0;
        w1 += a[i] > b[j];
        w2 += a[i] < b[j];
        w1 += a[i ^ 1] > b[j ^ 1];
        w2 += a[i ^ 1] < b[j ^ 1];
        ans += w1 > w2;
      }
    }
    cout << ans << '\n';
  }
}

