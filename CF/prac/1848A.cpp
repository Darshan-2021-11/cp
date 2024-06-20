#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static int T = 1, n, m, k, x, y, xi, yi;
bool yes;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    yes = true;
    cin >> n >> m >> k >> x >> y;
    for (u32 i = 0; i < k; ++i) {
      cin >> xi >> yi;
      if (!((abs(x - xi) + abs(y - yi)) & 1))
        yes = false;
    }
    cout << (yes ? "YES\n" : "NO\n");
  }
}

