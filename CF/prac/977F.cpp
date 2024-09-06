#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const int N = 200'001;
static map<i32, i32> m;
static map<i32, i32>::iterator it;
static i32 a[N], n, t, mx, mv;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n;
  for (i32 i = 0; i < n; ++i) {
    cin >> a[i];
    if ((it = m.find(a[i] - 1)) == m.end()) m[a[i]] = t = 1;
    else m[a[i]] = t = (*it).second + 1;
    if (t > mx) mx = t, mv = a[i] - t + 1;
  }
  cout << mx << '\n';
  for (i32 i = 0; i < n; ++i) {
    if (a[i] == mv) {
      cout << i + 1 << ' ';
      ++mv;
    }
  }
}
