#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static const u32 MAX = (u32)3e5 + 1, MOD = (u32)1e9 + 7;
static u32 TC, ans[MAX], n, k, row, col, sz;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  ans[0] = ans[1] = 1;
  for (u32 i = 2; i < MAX; ++i)
    ans[i] = (ans[i - 1] + ((u64)ans[i - 2] * (i - 1) << 1)) % MOD;
  cin >> TC;

  while (TC--) {
    cin >> n >> k;
    sz = k;
    for (u32 i = 0; i < k; ++i) {
      cin >> row >> col;
      sz += row != col;
    }
    cout << ans[n - sz] << '\n';
  }
}

