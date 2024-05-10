#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int T = 1, n, k, t, a[100 + 1];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cin >> n >> k;
    for (u32 i = 0; i < n; ++i) {
      cin >> t;
      ++a[t];
    }
    if (*max_element(a + 1, a + 101) >= k) cout << k - 1 << '\n';
    else cout << n << '\n';
    for (u32 i = 1; i <= 100; ++i) a[i] = 0;
  }
}

