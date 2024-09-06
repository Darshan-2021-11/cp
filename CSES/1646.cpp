#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const i32 N = 200'001;
  i64 a[N];
  i32 n, q;
  cin >> n >> q;
  for (i32 i = 1; i <= n; ++i) cin >> a[i];
  partial_sum(a + 1, a + n + 1, a + 1);
  for (i32 i = 0, l, r; i < q; ++i) {
    cin >> l >> r;
    cout << a[r] - a[l - 1] << '\n';
  }
}
