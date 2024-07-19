#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static i32 const N = 200'001;
static i32 TC, n, i, j, t, factors[N];

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  factors[1] = 1;
  for (i = 2; i < N; ++i) {
    if (factors[i]) {
      // for counting 1
      ++factors[i];
      continue;
    }
    for (j = i; j < N; j += i) {
      ++factors[j];
      t = j / i;
      while (!(t % i)) t /= i, ++factors[j];
    }
    // for counting 1
    ++factors[i];
  }
  while (TC--) {
    cin >> n;
    t = 0;
    for (i32 i = 1; i <= n; ++i) t = max(t, factors[i]);
    cout << t << '\n';
    for (i32 i = 1; i <= n; ++i) {
      cout << factors[i] << ' ';
    }
    cout << '\n';
  }
}
