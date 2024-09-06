#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 2;
static i64 TC;
static pair<i64, i64> a[2];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    for (i32 i = 0; i < 2; ++i) cin >> a[i].first >> a[i].second;
    sort(a, a + 2);
    if (a[0].first < a[1].first && a[0].second > a[1].second)
      cout << a[1].second - a[1].first + 2;
    else if (a[0].first == a[1].first && a[0].second == a[1].second)
      cout << a[1].second - a[1].first;
    else if (a[0].first == a[1].first)
      cout << a[0].second - a[0].first + 1;
    else if (a[0].second == a[1].second)
      cout << a[0].second - a[1].first + 1;
    else if (a[0].second < a[1].first)
      cout << 1;
    else cout << a[0].second - a[1].first + 2;
    cout << '\n';
  }
}
