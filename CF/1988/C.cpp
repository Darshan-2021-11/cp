#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static u64 T, n, t;
static vector<u64> ans;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;
  while (T--) {
    cin >> n;
    if (n && (n & (n - 1)) == 0) {
      cout << 1 << '\n' << n << '\n';
      continue;
    }
    for (i32 i = 59; i > -1; --i) {
      if ((t = static_cast<u64>(1) << i) & n) {
        ans.push_back(n ^ t);
      }
    }
    ans.push_back(n);
    cout << ans.size() << '\n';
    for (const auto &i: ans) cout << i << ' ';
    cout << '\n';
    ans.clear();
  }
}

