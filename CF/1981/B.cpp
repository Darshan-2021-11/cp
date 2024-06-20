#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 TC, n, m, l, r;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    cin >> n >> m;
    r = n + m;
    l = n > m ? n - m : 0;
    /*
    for (u32 i = 1 << 31; i; i >>= 1) {
      if ((i & r) == (i & l)) continue;
      n |= (i << 1) - 1;
      break;
    }
    cout << n << '\n';
    */
    while (l < r) l |= l + 1;
    cout << l << '\n';
  }
}
