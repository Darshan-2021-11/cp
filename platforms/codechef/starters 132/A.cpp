#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, n, m, i, j, k, a[(int)1e5], b[(int)1e5];
u64 maxSkill;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    maxSkill = 0;
    cin >> n >> m;
    for (i = 0; i < n; ++i) cin >> a[i];
    for (j = 0; j < m; ++j) cin >> b[j];
    if (n < 4 || m < 4 || n + m < 11) {
      cout << -1 << '\n';
      continue;
    }
    sort(a, a + n);
    sort(b, b + m);
    i = n - 1, j = m - 1;
    for (i = n - 1, k = 0; k < 4; --i, ++k)
      maxSkill += a[i];
    for (j = m - 1, k = 0; k < 4; --j, ++k)
      maxSkill += b[j];
    for (k = 0; k < 3; ++k) {
      if (i < n && j < m) {
        if (a[i] < b[j]) maxSkill += b[j--];
        else maxSkill += a[i--];
      } else if (i < n) maxSkill += a[i--];
      else maxSkill += b[j--];
    }
    cout << maxSkill << '\n';
  }
}

