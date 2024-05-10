#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 T = 1, n, i, a[(u32)2e5];
static ll ans;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    ans = 0;
    cin >> n;
    for (i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    for (i = 0; i < (n >> 1); ++i) {
      ans -= a[i];
    }
    for (; i < n; ++i) {
      ans += a[i];
    }
    cout << ans << '\n';
  }
}

