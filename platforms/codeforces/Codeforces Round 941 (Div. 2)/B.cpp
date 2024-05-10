#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int T = 1, n, m;
char a[500][500];
bool yes;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    yes = false;
    cin >> n >> m;
    for (u32 i = 0; i < n; ++i) {
      for (u32 j = 0; j < m; ++j) {
        cin >> a[i][j];
      }
    }
    if (n == 1) {
      if (a[0][0] == a[0][m - 1]) yes = true;
    } else if (m == 1) {
      if (a[0][0] == a[n - 1][0]) yes = true;
    } else {
      if (a[0][0] == a[n - 1][m - 1] || a[0][m - 1] == a[n - 1][0]) yes = true;
      if (a[0][0] == a[0][m - 1])
        for (u32 i = 1; i < m - 1; ++i) if (a[n - 1][i] == a[0][0]) yes = true;
      if (a[0][m - 1] == a[n - 1][m - 1])
        for (u32 i = 1; i < n - 1; ++i) if (a[i][0] == a[0][m - 1]) yes = true;
      if (a[n - 1][0] == a[n - 1][m - 1])
        for (u32 i = 1; i < m - 1; ++i) if (a[0][i] == a[n - 1][0]) yes = true;
      if (a[0][0] == a[n - 1][0])
        for (u32 i = 1; i < n - 1; ++i) if (a[i][m - 1] == a[0][0]) yes = true;
    }
    cout << (yes ? "YES\n": "NO\n");
  }
}

