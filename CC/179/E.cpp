#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int64_t sum, ans;
	int TC = 1, n, q, x, y, t, idx, a[N];
	cin >> TC;
	while (TC--) {
		sum = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
		sort(a, a + n);
		cin >> q;
		while (q--) {
			cin >> x >> y;
			idx = lower_bound(a, a + n, x) - a;
			if (idx == n) --idx;
			t = x - a[idx];
			if (t <= 0) {
				ans = max(y - (sum - a[idx]), static_cast<int64_t>(0));
				if (!idx) {
					cout << ans << '\n';
					continue;
				}
				--idx;
				t = x - a[idx];
				cout << min(ans, max(y - (sum - a[idx]), static_cast<int64_t>(0)) + t) << '\n';
			} else {
				cout << max(y - (sum - a[idx]), static_cast<int64_t>(0)) + t << '\n';
			}
		}
	}
}
