#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static i32 n, l, r;
static char c;
static map<i32, i32> mr, ml;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n;
  while (n--) {
    cin >> c >> r >> l;
    if (c == '+') {
      ++mr[r], ++ml[l];
    } else {
      if (--mr[r] == 0) mr.erase(r);
      if (--ml[l] == 0) ml.erase(l);
    }
    cout << (mr.size() && mr.upper_bound(ml.begin()->first) != mr.end() ? "YES" : "NO") << '\n';
  }
}

