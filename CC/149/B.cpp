#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const i32 N = 100;
  i32 TC = 1, a[N], n, i, j, c;
  cin >> TC;
  while (TC--) {
    cin >> n;
    for (i = 0; i < n; ++i) cin >> a[i];
    i = c = 0, j = n;
    while (i < n && a[i] <= 0) ++i;
    while (~j && a[j] <= 0) --j;
    while (i <= j) c += a[i++] < 0;
    cout << c << '\n';
  }
}

