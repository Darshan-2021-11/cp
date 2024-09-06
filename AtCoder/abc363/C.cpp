#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static i32 n, k, ans;
static char a[16];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> k;
  --k;
  for (i32 i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  do {
    bool yes = false;
    for (i32 i = 0; i + k < n; ++i) {
      bool p = true;
      for (i32 j = 0; j < k - j; ++j) p &= a[i + j] == a[i + k - j];
      yes |= p;
    }
    ans += !yes;
  } while (next_permutation(a, a + n));
  cout << ans;
}
