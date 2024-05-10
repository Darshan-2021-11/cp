#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int T = 1;
u64 n, t, d;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> n;
    for (d = u64(1e9) >> 1; d; d >>= 1) {
      while ((t + d) * (t + d + 1) >> 1 <= n) t += d;
    }
    cout << t + n - (t * (t + 1) >> 1) + 1 << '\n';
  }
}

