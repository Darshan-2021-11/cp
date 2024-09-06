#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i64 ans, dp[N];
static i32 TC, n, k, cnt1, t;
static bitset<N> a;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    ans = dp[0] = cnt1 = 0;
    cin >> n >> k;
    for (i32 i = 0; i < n; ++i) {
      cin >> t;
      cnt1 += t;
    }
    for (i32 i = 1, t = cnt1; i <= k; ++i) {
      dp[i] = t--;
    }
  }
}

