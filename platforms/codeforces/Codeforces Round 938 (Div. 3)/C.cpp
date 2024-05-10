#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, n, sunk, a[(u32)2e5];
u64 k;
bool front;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    sunk = 0, front = true;
    cin >> n >> k;
    for (u32 i = 0; i < n; ++i) cin >> a[i];
    u32 f = 0, b = n - 1;
    while (f < b) {
      if (front) {
        if (a[f] <= a[b]) {
          if (k < (a[f] << 1) - 1) goto ans;
          k -= (a[f] << 1) - 1, a[b] -= a[f] - 1, a[f++] = 0, ++sunk;
          front = !front;
        } else {
          if (k < (a[b] << 1)) goto ans;
          k -= (a[b] << 1), a[f] -= a[b], a[b--] = 0, ++sunk;
        }
      } else {
        if (a[b] <= a[f]) {
          if (k < (a[b] << 1) - 1) goto ans;
          k -= (a[b] << 1) - 1, a[f] -= a[b] - 1, a[b--] = 0, ++sunk;
          front = !front;
        } else {
          if (k < (a[f] << 1)) goto ans;
          k -= (a[f] << 1), a[b] -= a[f], a[f++] = 0, ++sunk;
        }
      }
    }
    if (f > b) goto ans;
    if (f == b) { if (a[f] <= k) ++sunk, k -= a[f], a[f] = 0; goto ans; }
ans:
    cout << sunk << '\n';
  }
}

