#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 1'000'000;
  int z[N], n = 0, l, r, i;
  char s[N];
  while ((s[n] = getchar_unlocked()) != '\n') ++n;
  z[0] = 0;
  for (i = 1, l = r = 0; i < n; ++i) {
    z[i] = 0;
    if (i <= r) z[i] = min(r - i, z[i - l]);
    while (i + z[i] < n && s[i + z[i]] == s[z[i]]) ++z[i];
    if (i + z[i] > r) l = i, r = z[i] + i;
  }
  for (i = n - 1; i; --i) if (z[i] == n - i) printf("%d ", n - i);
}
