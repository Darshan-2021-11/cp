#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 1'000'001;
  int TC = 1, a[N], mp[N], n, res;
  cin >> TC;
  while (TC--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], mp[a[i]] = i;
    res = 0;
    for (int i = 1, x, tmp; i <= n; ++i) {
      if (a[i] == i || a[x = a[i]] == i) continue;
      tmp = mp[i];
      swap(a[tmp], a[x]);
      swap(mp[a[tmp]], mp[a[x]]);
      res++;
    }
    cout << res << '\n';
  }
}
