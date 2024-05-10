#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

u32 T = 1, n, k, t, ans;
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	cin >> T;

	while (T--) {
		ans = UINT32_MAX;
		cin >> n >> k;
		if (n <= k) {
			cout << 1 << '\n';
			continue;
		}
		for (u32 i = 1; i * i <= n && i <= k; ++i) {
			if (n % i == 0) {
				t = n / i;
				ans = min(ans, t);
				if (t <= k) ans = min(ans, i);
			}
		}
		cout << ans << '\n';
	}
}

