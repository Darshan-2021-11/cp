#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = long double;

static i32 TC, n, m, k, a[500][500];
static i64 sum;
static char b;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    sum = 0;
    cin >> n >> m >> k;
    for (i32 i = 0; i < n; ++i) for (i32 j = 0; j < m; ++j) cin >> a[i][j];
    for (i32 i = 0; i < n; ++i) {
      for (i32 j = 0; j < m; ++j) {
        cin >> b;
        if (b == '1') a[i][j] *= -1;
        sum += a[i][j];
      }
    }
    cout << (sum % (k * k) ? "NO" : "YES") << '\n';
  }
}

