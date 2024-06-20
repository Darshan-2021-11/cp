#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 T = 1, n, a[(u32)2e5], bp, mx;
int main() {
  //ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> n >> a[0];
    for (u32 i = 1; i < n; ++i) {
      cin >> a[i];
      if (a[i] < a[i - 1]) ++bp;
    }
    cout << (!bp || (bp == 1 && a[0] >= a[n - 1]) ? "YES\n" : "NO\n");
    bp = 0;
  }
}

