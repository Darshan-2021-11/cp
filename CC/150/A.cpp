#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  i32 TC = 1, n, k, sum, t;
  cin >> TC;
  while (TC--) {
    sum = 0;
    cin >> n >> k;
    for (i32 i = 0; i < k; ++i) cin >> t, sum += t;
    for (i32 i = k; i < n - 1; ++i) cin >> t, cout << t << ' ';
    cin >> t;
    cout << t + sum << '\n';
  }
}

