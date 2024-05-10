#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1;
u64 l, r, lsqrt, rsqrt, t, ans;
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	cin >> T;

	while (T--) {
	  ans = 0;
	  cin >> l >> r;
	  lsqrt = sqrtl(l), rsqrt = sqrtl(r);
	  if (rsqrt - lsqrt == 0) {
      t = lsqrt * lsqrt;
      if (t == l) ++ans;
      t += lsqrt;
      if (t >= l && t <= r) ++ans;
      t += lsqrt;
      if (t >= l && t <= r) ++ans;
    } else {
      t = lsqrt * lsqrt;
      if (t == l) ++ans;
      t += lsqrt;
      if (t >= l) ++ans;
      t += lsqrt;
      if (t >= l) ++ans;

      ans += (rsqrt - (lsqrt + 1)) * 3;

      ++ans;
      t = rsqrt * rsqrt + rsqrt;
      if (t <= r) ++ans;
      t += rsqrt;
      if (t <= r) ++ans;
    }
    cout << ans << '\n';
	}
}

