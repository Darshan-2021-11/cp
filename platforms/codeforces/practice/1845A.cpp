#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int T = 1, n, k, x;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> n >> k >> x;
    if (n == 1) cout << "NO\n";
    else if (x != 1) {
      cout << "YES\n";
      cout << n << '\n';
      for (u32 i = 0; i < n; ++i) cout << 1 << ' ';
      cout << '\n';
    } else {
      if (n & 1) {
        if (k < 3) cout << "NO\n";
        else {
          cout << "YES\n";
          cout << 1 + ((n - 3) >> 1) << '\n';
          for (u32 i = 0; i < (n - 3) >> 1; ++i) cout << 2 << ' ';
          cout << 3 << '\n';
        }
      } else {
        if (k < 2) cout << "NO\n";
        else {
          cout << "YES\n";
          cout << (n >> 1) << '\n';
          for (u32 i = 0; i < n >> 1; ++i) cout << 2 << ' ';
          cout << '\n';
        }
      }
    }
  }
}

