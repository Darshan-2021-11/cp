#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, a[(u32)1e5], n, k, i, t, x, tmaxwins, maxwins;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    maxwins = 0, x = UINT32_MAX;
    cin >> n >> k;
    --k;
    for (i = 0; i < n; ++i) cin >> a[i];
    tmaxwins = 0;
    for (u32 i = 0; i < n; ++i) if (a[i] > a[k]) { x = i; break; }
    swap(a[0], a[k]);
    for (i = 1; i < n; ++i) {
      if (a[i] < a[0]) ++tmaxwins;
      else break;
    }
    maxwins = max(maxwins, tmaxwins);
    if (x < k) {
      swap(a[0], a[k]);
      swap(a[k], a[x]);
      tmaxwins = x != 0;
      for (i = x + 1; i < n; ++i) {
        if (a[i] < a[x]) ++tmaxwins;
        else
          break;
      }
      maxwins = max(maxwins, tmaxwins);
    }
    cout << maxwins << '\n';
  }
}
