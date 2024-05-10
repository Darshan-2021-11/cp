#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, n, t, ans, a[200'001], b[200'000];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    ans = 0;
    cin >> n;
    for (u32 i = 0; i < n; ++i) {
      cin >> b[i];
      if (++a[b[i]] == 2)
        ++ans;
    }
    cout << ans << '\n';
    for (u32 i = 0; i < n; ++i) {
      --a[b[i]];
    }
  }
}

