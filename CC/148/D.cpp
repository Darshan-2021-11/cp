#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned int;
using u64 = unsigned long long;
const u32 MOD = 1e9 + 7, N = 200'001;

u64 binpow(u64 a, u64 b) {
  a %= MOD;
  u64 res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  u32 t, n, sk, k, mn, extra, a[N];
  u64 ans;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (u32 i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    sk = 0;
    mn = __builtin_clz(a[0]);
    for (u32 i = 1, j, v; i < n; ++i) {
      if ((v = __builtin_clz(a[i])) == mn) continue;
      for (j = mn - 1; j >= v; --j) {
        if (sk + i <= k) sk += i;
        else { mn = j + 1; goto out; }
      }
      mn = v;
    }
out:
    for (u32 i = 0, j; i < n; ++i) {
      if ((j = __builtin_clz(a[i])) > mn) {
        a[i] <<= j - mn, k -= j - mn;
      }
      else break;
    }
    extra = k / n;
    k %= n;
    sort(a, a + n);
    for (u32 i = ans = 0; i < n; ++i) {
      if (k) ans += static_cast<u64>(a[i]) << 1, --k;
      else ans += a[i];
    }
    ans %= MOD;
    (ans *= binpow(2, extra)) %= MOD;
    cout << ans << '\n';
  }
}
