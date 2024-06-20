#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 TC, n, an, a[(u32)2e5], mx;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    cin >> n;
    an = 0;
    for (u32 i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    while (an < n) {
      mx = 0;
      for (u32 i = 0; i < n; ++i) {
        if (a[i] == -1) continue;
        mx = max(mx, -1 & a[i]);
      }
      for (u32 i = 0; i < n; ++i) {
        if (a[i] == -1) continue;
        if ((-1 & a[i]) == mx) {
          cout << a[i] << ' ';
          a[i] = -1, ++an;
        } else a[i] &= mx;
      }
    }
    cout << '\n';
  }
}

