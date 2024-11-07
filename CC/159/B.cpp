#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 1e6 + 1;
  int64_t TC = 1, h, k, t;
  int sieve[N] {}, ans;
  for (int64_t i = 2; i < N; ++i) {
     if (!sieve[i]) sieve[i] = 1;
    for (int64_t j = i * i; j < N; j += i) {
      if (sieve[j]) continue;
      sieve[j] = i;
    }
  }
  cin >> TC;
  while (TC--) {
    ans = 0, t = 1;
    cin >> h >> k;
    while ((t << 1) <= k) ++ans, t <<= 1;
    while (h != 1) ++ans, h = sieve[h];
    cout << ans << '\n';
  }
}
