#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int T = 1, n, t;
char c, p;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    t = 1;
    cin >> n >> c;
    cout << t << ' ';
    p = c;
    for (u32 i = 2; i < n; ++i) {
      cin >> c;
      if (c != p) {
        t = i;
      }
      cout << t << ' ';
      p = c;
    }
    cout << '\n';
  }
}

