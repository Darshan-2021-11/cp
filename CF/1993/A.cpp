#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 400;
static i32 TC, n, a[N], cnt[4], ans;
static char c;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    ans = 0;
    fill(cnt, cnt + 4, 0);
    cin >> n;
    for (i32 i = 0; i < (n << 2); ++i) {
      cin >> c;
      ++cnt[c - 'A'];
    }
    for (i32 i = 0; i < 4; ++i) {
      ans += min(cnt[i], n);
    }
    cout << ans << '\n';
  }
}
