#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
long long binpow(long long a, long long b) {
    a %= MOD;
    long long res = 1;
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
  const int N = 200'000;
  int TC = 1, a[N], cnt[2], n, mx, mxidx;
  int64_t sum[3];
  cin >> TC;
  while (TC--) {
    mx = 0;
    fill_n(sum, 3, 0);
    fill_n(cnt, 2, 0);
    cin >> n;
    for (int i = 0, t; i < n; ++i) {
      cin >> a[i], t = a[i];
      if (a[i] >= mx || inc) {
        mx = a[i],
        mxidx = i,
        sum[0] = sum[2],
        cnt[0] = cnt[1],
        sum[1] = cnt[1] = 0;
      }
      sum[1] += a[i];
      while (!(t & 1)) ++cnt[1];
      sum[2] += t;
    }
    cout << '\n';
  }
}
