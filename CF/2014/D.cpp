#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 100'001;
  int TC = 1, n, d, k, laps;
  array<int, 2> a[N];

  cin >> TC;
  while (TC--) {
    cin >> n >> d >> k;
    for (int i = 0; i < k; ++i)
      cin >> a[i][0] >> a[i][1];

    laps = 0;
    sort(a, a + k);
    multiset<int> ms;
    array<int, 2> b{ 0, -1 }, m{ INT_MAX, -1 };
    for (int i = 1, j = 0; i <= n - d + 1; ++i) {
      while ((j < k) && (a[j][0] >= i) && (a[j][0] < i + d))
        ++laps, ms.insert(a[j++][1]);
      while (ms.size() && ((*ms.begin()) < i))
        ms.erase(ms.begin()), --laps;
      if (laps > b[0]) b[0] = laps, b[1] = i;
      if (laps < m[0]) m[0] = laps, m[1] = i;
    }
    cout << b[1] << ' ' << m[1] << '\n';
  }
}
