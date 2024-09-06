#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const i32 N = 200'000;
  i32 TC = 1, a[N], n;
  cin >> TC;
  while (TC--) {
    cin >> n;
    for (i32 i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    for (i32 i = 1; i < n; i += 2) {
      if ((a[i - 1] <= 0 && a[i] <= 0) || abs(a[i - 1]) > a[i])
        a[i - 1] = -a[i - 1], a[i] = -a[i];
      else break;
    }
    cout << accumulate(a, a + n, i64{}) << '\n';
  }
}

