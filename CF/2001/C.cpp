#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  i32 TC, n, edges[1000];
  cin >> TC;
  while (TC--) {
    cin >> n;
    for (i32 i = 2, t; i <= n; ++i) {
      edges[i - 2] = 1;
      while (true) {
        cout << "? " << i << ' ' << x << endl; cin >> t;
        if (t == i) break;
        edges[i - 2] = t;
      }
    }
    cout << "! ";
    for (i32 i = 2; i <= n; ++i) cout << i << ' ' << edges[i - 2] << ' ';
    cout << endl;
  }
}
