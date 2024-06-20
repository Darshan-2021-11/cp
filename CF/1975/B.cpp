#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 T = 1, n, i, t, a[(u32)1e5];
int main() {
  //ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> n;
    for (i = 0; i < n; ++i)
      cin >> a[i];
    sort(a, a + n);
    i = 0;
    while (++i < n && (a[i] % a[0] == 0));
    t = i;
    while (++i < n && (a[i] % a[t] == 0 || a[i] % a[0] == 0));
    if (i >= n) cout << "YES\n";
    else cout << "NO\n";
  }
}

