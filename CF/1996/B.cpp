#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 1000;
static i32 TC, n, k, p, q;
static char a[N][N], c;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cin >> n >> k;
    p = q = 0;
    for (i32 i = 0; i < n; ++i) {
      if (i % k == 0) {
        q = 0;
        for (i32 j = 0; j < n; ++j) {
          cin >> c;
          if (j % k == 0) a[p][q++] = c;
        }
        ++p;
      } else 
        for (i32 j = 0; j < n; ++j)
          cin >> c;
    }
    for (i32 i = 0; i < p; ++i) {
      for (i32 j = 0; j < q; ++j) cout << a[i][j];
      cout << '\n';
    }
  }
}

