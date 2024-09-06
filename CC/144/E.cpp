#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 5'001;
static i32 TC, n, k, c0;
static i64 inv, mninv;
static char a[N], b[N];

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cin >> n >> k;
    mninv = INT_MAX;
    for (i32 i = 0; i < n; ++i) cin >> a[i], a[i] ^= '0';
    for (i32 j = 0; j <= k; ++j) {
      for (i32 i = 0; i < n; ++i) b[i] = a[i];
      for (i32 i = 0, x = j; x && i < n; ++i) if (b[i]) b[i] ^= 1, --x;
      for (i32 i = n - 1, x = k - j; x && ~i; --i) if (!b[i]) b[i] ^= 1, --x;
      c0 = 0, inv = 0;
      for (i32 i = n - 1; ~i; --i) {
        if (b[i] == 1) inv += c0;
        else ++c0;
      }
      mninv = min(mninv, inv);
    }
    cout << mninv << '\n';
  }
}

