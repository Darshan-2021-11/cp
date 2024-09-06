#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const i32 N = 300'000;
  i32 T = 1, n, a[N], mp[3], lst[3];
  cin >> TC;
  while (TC--) {
    fill_n(mp, 3, 0); fill_n(lst, 3, -1);
    cin >> n;
    for (i32 i = 0; i < n; ++i) cin >> a[i], ++mp[--a[i]];
    for (i32 i = 0; i < n; ++i) {
      --mp[a[i]];
    }
  }
}

