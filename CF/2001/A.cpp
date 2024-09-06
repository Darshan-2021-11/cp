#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 101;
static i32 TC, n, mn, a[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    mn = N;
    cin >> n;
    fill_n(a, N, 0);
    for (i32 i = 0, t; i < n; ++i) {
      cin >> t;
      ++a[t];
    }
    for (i32 i = 0; i < N; ++i) mn = min(mn, n - a[i]);
    cout << mn << '\n';
  }
}

