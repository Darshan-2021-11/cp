#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i32 TC, n, a[N];
static bool yes;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    yes = true;
    cin >> n;
    cin >> a[0];
    for (i32 i = 1; i < n; ++i) {
      cin >> a[i];
      yes &= a[i] == a[0];
    }
    sort(a, a + n);
    n = unique(a, a + n) - a;
    if (yes || (n == 2 && a[0] == 0)) cout << "YES\n";
    else cout << "NO\n";
  }
}

