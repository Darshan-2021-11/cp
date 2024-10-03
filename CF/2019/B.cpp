#pragma GCC optimize("O3,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 100'000;
  int TC = 1, n, q, k, a[N];
  int64_t seg;
  cin >> TC;
  while (TC--) {
    map<int64_t, int64_t> m;
    map<int64_t, int64_t>::iterator it;
    cin >> n >> q;
    cin >> a[0];
    seg = n - 1;
    for (int i = 1; i < n; ++i) {
      cin >> a[i];
      ++m[seg];
      if (a[i] - a[i - 1] - 1)
        m[seg - i + 1] += a[i] - a[i - 1] - 1;
      seg += n - (i << 1);
    }
    ++m[seg];
    while (q--) {
      cin >> k;
      if ((it = m.find(k)) == m.end()) cout << 0 << ' ';
      else cout << it->second << ' ';
    }
    cout << '\n';
  }
}
