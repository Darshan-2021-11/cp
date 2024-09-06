#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const i32 N = 200'000;
  i32 TC = 1, n, i;
  i64 dc, tk;
  char p, t;
  bitset<N> b;
  cin >> TC;
  while (TC--) {
    tk = dc = 0;
    cin >> n;
    cin >> p;
    b[0] = p ^ '0';
    for (i = 1; i < n; ++i, p = t) cin >> t, b[i] = t ^ '0', tk += p != t, dc += p == t;
    cout << tk * dc + (tk * (tk - 1) >> 1) << '\n';
  }
}

