#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i32 TC, n, i, i1;
static char a[N], b[N];
static bool eq;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    eq = true;
    cin >> n;
    for (i = 0; i < n; ++i) cin >> a[i];
    for (i = 0; i < n; ++i) cin >> b[i];
    for (i = 0; i < n && a[i] == '0'; ++i);
    if (i == n) {
      for (i = 0; i < n; ++i) eq &= a[i] == b[i];
    } else {
      i1 = i;
      for (i = 0; i < i1; ++i) eq &= a[i] == b[i];
    }
    cout << (eq ? "YES\n": "NO\n");
  }
}

