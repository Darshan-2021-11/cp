#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 200'000;
  int64_t TC = 1, n, m, mx, k, a[2];
  char s[N];
  cin >> TC;
  while (TC--) {
    a[0] = a[1] = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) cin >> s[i], s[i] -= 'A';
    mx = max(n, m);
    for (int i = 0; i < mx - 1; ++i) {
      if (a[!s[i % k]]) a[!s[i % k]] -= 2;
      a[s[i % k]] += n + m - 1;
      cout << a[0] << ',' << a[1] << ' ';
    }
    if (a[0] == a[1]) cout << "DRAW\n";
    else if (a[0] > a[1]) cout << "ALICE\n";
    else cout << "BOB\n";
  }
}
