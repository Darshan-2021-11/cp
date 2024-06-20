#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 T = 1, x, logx;
static bool inc;
static char a[32];
int main() {
  //ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> x;
    while (x) {
      a[logx++] = x & 1, x >>= 1;
    }

    for (u32 i = 1; i < logx; ++i) {
      if (a[i] & a[i - 1]) {
        if (!inc) {
          a[i - 1] = - 1;
          inc = true;
        } else a[i - 1] = 0;
      } else if (inc) {
        swap(a[i], a[i - 1]);
        inc = false;
      }
    }
    if (inc) swap(a[logx], a[logx - 1]), ++logx;
    cout << logx << '\n';
    for (u32 i = 0; i < logx; ++i) cout << (int)a[i] << ' ';
    cout << '\n';
    memset(a, 0, 32), logx = inc = 0;
  }
}

