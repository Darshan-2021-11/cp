#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 n, m, k, c, x, xi[100], ri[100], xn, rn, t, ans;
static char r;
static bool result;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> m >> k;
  for (u32 i = 0, x = 0; i < m; ++i, x = 0) {
    cin >> c;
    for (u32 j = 0; j < c; ++j)
      cin >> t, x |= 1 << t - 1;
    cin >> r;
    xi[xn++] = x, ri[rn++] = r == 'o';
  }
  for (u32 i = 0; i < (1 << n); ++i) {
    result = true;
    for (u32 j = 0; j < m; ++j)
      if ((__builtin_popcount(i & xi[j]) >= k) != ri[j]) result = false;
    ans += result;
  }
  cout << ans;
}
