#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int64_t TC = 1, a[N], n, m, ans, x;
	pair<int64_t, int64_t> b[N];
	cin >> TC;
	while (TC--) {
		ans = 0;
		cin >> n >> m;
		for (int i = 0, idx = 0; i < n; ++i) {
			b[i].first = b[i].second = 0;
			for (int j = 0; j < m; ++j) cin >> a[idx], b[i].second += a[idx], a[idx++] *= (m - j);
			for (int j = m; j; --j) b[i].first += a[idx - j];
			swap(b[i].first, b[i].second);
		}
		sort(b, b + n, greater<pair<int64_t, int64_t>>());
		x = 0;
		for (int i = 0, idx = 0; i < n; ++i) {
			if (i) x += b[i - 1].first;
			ans += b[i].second + x * m;
		}
		cout << ans << '\n';
	}
}
