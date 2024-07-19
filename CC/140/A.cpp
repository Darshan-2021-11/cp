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

static i32 TC, n, a[100], t;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    t = 0;
    memset(a, 0, sizeof(a));
    cin >> n;
    for (i32 i = 0; i < n; ++i) cin >> t, ++a[t - 1];
    for (i32 i = n - 1; ~i; --i) {
      if (!a[i]) ++t;
      else t -= a[i] - 1;
    }
    if (t == 0) cout << "YES\n";
    else cout << "NO\n";
  }
}

