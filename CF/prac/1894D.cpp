#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i64 TC, a[N], b[N], n, m, j;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cin >> n >> m;
    for (i32 i = 0; i < n; ++i) cin >> a[i];
    for (i32 i = 0; i < m; ++i) cin >> b[i];
    sort(b, b + m, greater<i32>());
    j = 0;
    for (i32 i = 0; i < n; ++i) {
      while (j < m && b[j] >= a[i]) cout << b[j++] << ' ';
      cout << a[i] << ' ';
    }
    while (j < m) cout << b[j++] << ' ';
    cout << '\n';
  }
}

