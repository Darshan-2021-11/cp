#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  const int N = 100'000;
  int n, m, k, q, r, c, l, h, l1, h1, x, a[N];
  char o;
  cin >> n >> k >> q;
  for (int i = 0; i < n; ++i) for (int j = 0; j < k; ++j)
    cin >> a[i * k + j];
  for (int i = 1; i < n; ++i) for (int j = 0; j < k; ++j)
    a[i * k + j] |= a[(i - 1) * k + j];
  /*
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j)
      cout << a[i * k + j] << ' ';
    cout << '\n';
  }
  */
  while (q--) {
    cin >> m;
    l = 0, h = n - 1;
    while (m--) {
      cin >> r >> o >> c;
      if (l > h) continue;
      --r;
      if (o == '>') {
        l1 = l, h1 = h + 1;
        while (l1 < h1) {
          x = (l1 + h1) >> 1;
          //cout << x << ',' << l1 << ',' << h1 << ' ';
          if (a[x * k + r] > c) h1 = x;
          else l1 = x + 1;
        }
        l = max(l1, l);
      } else {
        l1 = l - 1, h1 = h;
        while (l1 < h1) {
          x = (l1 + h1 + 1) >> 1;
          //cout << x << ',' << l1 << ',' << h1 << ' ';
          if (a[x * k + r] < c) l1 = x;
          else h1 = x - 1;
        }
        h = min(h1, h);
      }
      //cout << '\n';
    }
    if (l > h) cout << -1 << '\n';
    else cout << l + 1 << '\n';
  }
}
