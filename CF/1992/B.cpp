#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i64 N = 200'000;
static i64 T, n, k, a, mx;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;
  while (T--) {
    mx = 0;
    cin >> n >> k;
    for (i32 i = 0; i < k; ++i) {
      cin >> a;
      mx = max(a, mx);
    }
    cout << (((n - mx) << 1) - k + 1) << '\n';
  }
}

