#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i32 TC, n, a[N], same, mex;
bitset<N> present;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    same = 0, mex = 0;
    cin >> n;
    for (i32 i = 1; i <= n; ++i) {
      cin >> a[i];
      same += (a[i] == i) && (mex == i - 1);
      present[a[i]] = true;
      while (mex + 1 <= n && present[mex + 1]) ++mex;
    }
    if (same == n) cout << 0 << '\n';
    else if (same) cout << 1 << '\n';
    else if (a[1] != n || a[n] != 1) cout << 2 << '\n';
    else cout << 3 << '\n';
    for (i32 i = 1; i <= n; ++i) present[i] = false;
  }
}
