#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 300'001;
static i32 TC, n, a[N], b[N], eq;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cin >> n;
    for (i32 i = 0; i < n; ++i) cin >> a[i];
    for (i32 i = 0; i < n; ++i) cin >> b[i];
    eq = 1;
    for (i32 i = 0; i < n; ++i) {
      eq &= a[i] == b[i];
    }
    if (eq) {
      cout << "Bob\n";
      continue;
    }
    eq = 1;
    for (i32 i = 0; i < n; ++i) {
      eq &= a[n - i - 1] == b[i];
    }
    cout << (eq ? "Bob" : "Alice") << '\n';
  }
}

