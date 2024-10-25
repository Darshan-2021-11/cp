#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 1'000'001;
  int z[N], n = 0, m = 0, ans = 0, i, l, r, t;
  char s[N], p[N];
  while ((s[n] = getchar_unlocked()) != '\n') ++n;
  while ((p[m] = getchar_unlocked()) != '\n') ++m;
  if (n < m) {
    putchar_unlocked('0');
    return 0;
  }
  z[0] = 0;
  for (z[0] = l = r = 0, i = 1; i < m; ++i) {
    z[i] = 0;
    if (i <= r) {
      z[i] = min(r - i + 1, z[i - l]);
    }
    while (i + z[i] < m && p[i + z[i]] == p[z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    ans += z[i] == m;
  }
  for (i = l = r = 0; i <= n - m; ++i) {
    t = 0;
    if (i <= r) {
      t = min(r - i + 1, z[i - l]);
    }
    while (i + t < n && s[i + t] == p[t]) ++t;
    if (i + t - 1 > r) l = i, r = i + t - 1;
    ans += t == m;
  }
  cout << ans;
}
