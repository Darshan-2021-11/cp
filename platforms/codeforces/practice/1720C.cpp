#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, n, m, cnt1;
char a[500][500];
bool consec0;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    cnt1 = consec0 = 0;
    cin >> n >> m;
    for (u32 i = 0; i < n; ++i) {
      for (u32 j = 0; j < m; ++j) {
        cin >> a[i][j];
        a[i][j] -= '0';
        if (a[i][j]) ++cnt1;
        if (j && !a[i][j] && !a[i][j - 1]) consec0 = true;
      }
    }
    if (cnt1 == n * m) {
      cout << (cnt1 > 1 ? cnt1 - 2: 0) << '\n';
      continue;
    } else if (consec0) {
      cout << cnt1 << '\n';
      continue;
    }
    for (u32 j = 1; j < n; ++j) {
      for (u32 i = 0; i < m; ++i) {
        if (!a[j][i] && !a[j - 1][i]) {
          consec0 = true;
          break;
        }
      }
    }
    if (consec0) {
      cout << cnt1 << '\n';
      continue;
    }
    for (u32 i = 0; i < n - 1; ++i) {
      for (u32 j = 0; j < m - 1; ++j) {
        if (!a[i][j] && !a[i + 1][j + 1]) {
          consec0 = true;
          break;
        }
      }
    }
    if (consec0) {
      cout << cnt1 << '\n';
      continue;
    }
    for (u32 i = 0; i < n - 1; ++i) {
      for (u32 j = 1; j < m; ++j) {
        if (!a[i][j] && !a[i + 1][j - 1]) {
          consec0 = true;
          break;
        }
      }
    }
    if (consec0)
      cout << cnt1 << '\n';
    else cout << (cnt1 ? cnt1 - 1: 0) << '\n';
  }
}
