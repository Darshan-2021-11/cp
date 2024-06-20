#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 T = 1, n, a[(u32)1e5], mx;
int main() {
  //ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> n;
    for (u32 i = 0; i < n; ++i) cin >> a[i];
    for (u32 i = 1; i < n; ++i)
      mx = max(mx, min(a[i - 1], a[i]));
    for (u32 i = 2; i < n; ++i)
      if (a[i] >= a[i - 1] && a[i - 1] <= a[i - 2]) mx = max(mx, min(a[i - 2], a[i]));
    cout << mx << '\n';
    mx = 0;
  }
}
