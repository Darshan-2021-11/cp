//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static const u64 MOD = 998244353;
static u64 ans, n, m, t, mask;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> m;
  for (u32 i = 59; ~i; --i) {
    t = 1ULL << i;
    if (!(m & t)) continue;
    mask = ~((t - 1) | t);
    if (n & mask) ans = (((ans + ((((n & mask) >> i + 1) % MOD) * (t % MOD))) % MOD)) % MOD;
    if (n & t) ans = (ans + ((n & (t - 1)) % MOD) + 1) % MOD;
  }
  cout << ans;
}
