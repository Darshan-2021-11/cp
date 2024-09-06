#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 100'001;
static i32 TC, n, a[N], b[N];
static bool yes;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    yes = true;
    cin >> n;
    for (i32 i = 1; i < n; ++i) cin >> b[i];
    a[0] = b[1];
    for (i32 i = 1; i < n - 1; ++i) a[i] = b[i] | b[i + 1];
    a[n - 1] = b[n - 1];
    for (i32 i = 0; i < n - 1; ++i) if ((a[i] & a[i + 1]) != b[i + 1]) { yes = false; break; }
    if (yes) for (i32 i = 0; i < n; ++i) cout << a[i] << ' ';
    else cout << -1;
    cout << '\n';
  }
}

