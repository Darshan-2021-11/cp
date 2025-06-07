#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int64_t TC = 1, n, m, a, b, c[2], d[2], t, ans;
	cin >> TC;
	while (TC--) {
		ans = INT_MAX;
		cin >> n >> m >> a >> b;
		d[0] = min(a, n - a + 1);
		d[1] = min(b, m - b + 1);
		c[0] = c[1] = 0;
		while (n > 1) ++c[0], n = n + 1 >> 1;
		while (m > 1) ++c[1], m = m + 1 >> 1;
		for (int i = 0; i < 2; ++i) {
			t = 1;
			while (d[i] > 1) ++t, d[i] = d[i] + 1 >> 1;
			ans = min(ans, t + c[1 ^ i]);
		}
		cout << ans << '\n';
	}
}
