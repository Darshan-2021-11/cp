#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u64 n, y, x, ans;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n;
  while (n--) {
    cin >> y >> x;
    if (y > x) {
      if (y & 1) --y, ans = y * y + x;
      else ans = y * y - (x - 1);
    } else {
      if (x & 1) ans = x * x - (y - 1);
      else --x, ans = x * x + y;
    }
    cout << ans << '\n';
  }
}

