#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 a, n, ans;
bool t[100], b1, b2;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> a;
  --a;
  for (u32 i = 0; i < n; ++i) cin >> t[i];
  int x = a - 1, y = a + 1;
  if (t[a]) ++ans;
  while (true) {
    b1 = x >= 0, b2 = y <= n - 1;
    if (b1 && b2) {
      if (t[x] && t[y]) ans += 2;
      --x, ++y;
    } else if (b1) {
      if (t[x]) ++ans;
      --x;
    } else if (b2) {
      if (t[y]) ++ans;
      ++y;
    } else break;
  }
  cout << ans << '\n';
}

