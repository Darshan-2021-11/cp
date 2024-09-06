#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

const i32 N = 200'001;
static i32 TC, n, s, m, a[N], b[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    i32 yes = 0;
    cin >> n >> s >> m;
    for (i32 i = 1; i <= n; ++i) cin >> a[i] >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for (i32 i = 1; i <= n; ++i) {
      yes |= a[i] - b[i - 1] >= s;
    }
    yes |= m - b[n] >= s;
    cout << (yes ? "YES\n": "NO\n");
  }
}

