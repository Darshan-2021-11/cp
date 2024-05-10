#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 n, m, rounds, p1, p2, x, y, a[(u32)2e5 + 1], b[(u32)2e5 + 1];
bool xr, yr;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> m;
  for (u32 i = 1; i <= n; ++i) {
    cin >> a[i];
    if (!b[a[i] - 1]) ++rounds;
    b[a[i]] = true;
  }
  for (u32 i = 1; i <= n; ++i) {
    b[a[i]] = i;
  }
  for (u32 i = 0; i < m; ++i) {
    cin >> p1 >> p2;
    if (p1 == p2) {
      cout << rounds << '\n';
      continue;
    }
    x = a[p1], y = a[p2];
    // for y - 1
    xr = p1 > b[y - 1];
    yr = p2 > b[y - 1];
    if (xr ^ yr) {
      if (xr) --rounds;
      else ++rounds;
    }
    // for y + 1
    xr = p1 > b[y + 1];
    yr = p2 > b[y + 1];
    if (xr ^ yr) {
      if (xr) ++rounds;
      else --rounds;
    }
    // for x - 1
    xr = p1 > b[x - 1];
    yr = p2 > b[x - 1];
    if (xr ^ yr) {
      if (xr) ++rounds;
      else --rounds;
    }
    // for x + 1
    xr = p1 > b[x + 1];
    yr = p2 > b[x + 1];
    if (xr ^ yr) {
      if (xr) --rounds;
      else ++rounds;
    }
    swap(b[x], b[y]);
    swap(a[p1], a[p2]);
    cout << rounds << '\n';
  }
}
