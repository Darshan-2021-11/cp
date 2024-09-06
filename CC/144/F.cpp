#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i32 TC, i, t, n;
static i64 l, r, sum, bl, br, bm, lb;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    cin >> n >> l >> r;
    sum = bl = lb = 0, br = n;
    while (bl <= br) {
      bm = (bl + br) >> 1;
      if ((bm * (bm + 1)) >> 1 < l) lb = bm, bl = bm + 1;
      else br = bm - 1;
    }
    for (i = 1; i < lb; ++i) cout << i << ' ', sum += i;
    t = l - 1 - sum;
    if (t) cout << t << ' ';
    for (i = n; i > lb; --i) if (i != t) cout << i << ' ';
    if (lb) cout << lb;
    cout << '\n';
  }
}
