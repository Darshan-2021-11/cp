#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

static int TC, i, j, idx, n, a[(int)2e5 + 1], b[(int)2e5 + 1], c[(int)2e5 + 1], ci;
static bool ins, yes;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    yes = false;
    cin >> n;
    for (i = 0; i < n; ++i) cin >> a[i];
    if (n == 3) {
      cout << "YES\n";
      continue;
    }
    for (i = 0; i < n - 1; ++i) b[i] = gcd(a[i], a[i + 1]);
    for (i = 0; i < n - 2; ++i) if (b[i] > b[i + 1]) break;
    idx = i;
    for (j = idx; j < min(n, idx + 3); ++j) {
      ci = ins = false;
      for (i = 0; i < n - 1; ++i) {
        if (i != j - 1 & i != j) c[ci++] = b[i];
        else if (!ins) {
          ins = true;
          if (!j) continue;
          else c[ci++] = gcd(a[j - 1], a[j + 1]);
        }
      }
      if (is_sorted(c, c + n - 2)) { yes = true; break; }
    }
    cout << (yes ? "YES\n" : "NO\n");
  }
}
