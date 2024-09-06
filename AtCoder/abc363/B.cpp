#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static i64 n, t, p, a[100];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> t >> p;
  for (i32 i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  cout << (a[n - p] >= t ? 0 : t - a[n - p]);
}

