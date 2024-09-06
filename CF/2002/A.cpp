#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static i64 TC, n, m, k;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cin >> n >> m >> k;
    if (n >= k && m >= k) cout << k * k << '\n';
    else if (m >= k) cout << n * k << '\n';
    else if (n >= k) cout << m * k << '\n';
    else cout << n * m << '\n';
  }
}

