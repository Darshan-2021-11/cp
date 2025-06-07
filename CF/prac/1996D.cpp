#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int64_t ans;
	int TC = 1, n, x;
	cin >> TC;
	while (TC--) {
		ans = 0;
		cin >> n >> x;
		for (int a = 1; a < x; ++a) {
			for (int b = 1, u, v; a + b < x; ++b) {
				ans += min(u = x - a - b, v = max(0, (n - a * b) / (b + a)));
				if (!u || !v) break;
			}
		}
		cout << ans << '\n';
	}
}
