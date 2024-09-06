#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i32 TC, n, flips;
static char a[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    flips = 0;
    cin >> n;
    cin >> a[0];
    for (i32 i = 1; i < n; ++i) {
      cin >> a[i];
      if (a[i] != a[i - 1]) ++flips;
    }
    if (flips & 1) {
      cout << 1 << '\n';
    } else {
      cout << (a[0] == '0' ? min(n, 2) : 0) << '\n';
    }
  }
}
