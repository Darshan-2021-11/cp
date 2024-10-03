#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const i32 N = 1001;
  i32 p[N], cc[N]{}, cnt[N]{}, n, isSpruce = true;
  cin >> n;
  for (i32 i = 1, t; i < n; ++i) cin >> p[i], --p[i], ++cc[p[i]];
  for (i32 i = 1, t; i < n; ++i) cnt[p[i]] += cc[i] == 0;
  for (i32 i = 0; i < n; ++i) if (cc[i]) isSpruce &= cnt[i] > 2;
  cout << (isSpruce ? "YES" : "NO") << '\n';
}
