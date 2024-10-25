#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 1'000'000;
  int TC = 1, n, hk[N], hkn, nhkn;
  int64_t sum;
  char c;
  cin >> TC;
  while (TC--) {
    sum = 0;
    hkn = N - 1, nhkn = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> c;
      if (c == '0') hk[nhkn++] = i;
      else hk[hkn--] = i;
    }
    --nhkn, ++hkn;
    while (~nhkn && hkn < N) {
      if (hk[nhkn] > hk[hkn]) sum += hk[hkn], ++hkn, --nhkn;
      else if ((hkn += 2) <= N) sum += hk[hkn - 1];
    }
    while ((hkn += 2) <= N) sum += hk[hkn - 1];
    cout << sum << '\n';
  }
}
