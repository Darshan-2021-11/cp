#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int64_t TC = 1, n, m, res, ans, x, u;
	array<int64_t, 2> a[N], b[N];
	cin >> TC;
	while (TC--) {
		res = 0;
		cin >> n >> m;
		for (int i = 0; i < n; ++i) cin >> a[i][1];
		for (int i = 0; i < n; ++i) cin >> a[i][0];
		sort(a, a + n);
		m = x = ans = 0;
		while (m < n) {
			ans = 0;
			while (a[m][0] < x && m < n) ++m;
			if (m >= n) break;
			for (int i = m; i < n; ++i) {
				u = sqrtl(a[i][0] * a[i][0] - x * x);
				b[i - m][0] = a[i][1] - u;
				b[i - m][1] = a[i][1] + u;
			}
			sort(b, b + n - m);
			for (int i = 1; i < n - m; ++i) {
				if (b[i][0] > b[i - 1][1]) ans += b[i - 1][1] - b[i - 1][0] + 1;
				else b[i][0] = b[i - 1][0], b[i][1] = max(b[i][1], b[i - 1][1]);
			}
			ans += b[n - m - 1][1] - b[n - m - 1][0] + 1;
			if (x) res += ans << 1;
			else res += ans;
			++x;
		}
		cout << res << '\n';
	}
}
