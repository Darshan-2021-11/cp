#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, n, k;
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	cin >> T;

	while (T--) {
	  cin >> n >> k;
	  for (u32 i = 1; i <= n; ++i) {
      if (k >= i) {
        cout << 2 << ' ';
        k -= i;
      } else if (k) {
        cout << - int((i - k) << 1) + 1 << ' ';
        k = 0;
      } else cout << -1000 << ' ';
    }
    cout << '\n';
	}
}

