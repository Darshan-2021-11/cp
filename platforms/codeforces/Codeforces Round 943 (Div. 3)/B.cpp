#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

int T = 1, i, n, m, ans;
char a[(int)2e5], b[(int)2e5];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    ans = 0;
    cin >> n >> m;
    for (i = 0; i < n; ++i) cin >> a[i];
    for (i = 0; i < m; ++i) cin >> b[i];
    for (ans = 0, i = 0; i < m && ans < n; ++i) {
      if (a[ans] == b[i]) ++ans;
    }
    cout << ans << '\n';
  }
}

