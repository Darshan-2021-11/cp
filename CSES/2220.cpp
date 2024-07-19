#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static i64 a, b;

const static bool check_adj(i32 i) {
  const string num = to_string(i);
  for (i32 k = 1; k < num.size(); ++k) {
    if (num[k] == num[k - 1]) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> a >> b;
  i32 t = 1;
  for (i32 i = 0, ans = 0; i < 1e8; ++i) {
    if (!check_adj(i)) ++ans;
    if (i == t - 1) {
      cout << i << ':' << ans << '\n';
      t *= 10;
    }
  }
}

