#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int64_t binpow(int64_t a, int64_t b) {
  a %= MOD;
  int64_t res = 1;
  while (b) {
    if (b & 1) (res *= a) %= MOD;
    (a *= a) %= MOD;
    b >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 200'000;
  int64_t x[2], sum;
  int TC = 1, n, an, a[N][2];
  cin >> TC;
  while (TC--) {
    sum = an = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> x[0];
      x[0] >>= (x[1] = __builtin_ctzll(x[0]));
      while (an && (x[1] > 29 || a[an - 1][0] < x[0] << x[1])) {
        --an;
        sum -= (binpow(2, a[an][1]) * a[an][0]) % MOD;
        if (sum < 0) sum += MOD;
        sum += a[an][0], x[1] += a[an][1];
        if (sum >= MOD) sum -= MOD;
      }
      (sum += binpow(2, x[1]) * x[0]) %= MOD;
      a[an][0] = x[0], a[an][1] = x[1], ++an;
      cout << sum << " \n"[i == n];
    }
  }
}
