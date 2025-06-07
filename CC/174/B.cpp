#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 50;
	int TC = 1, n, ans;
	vector<int> a;
	a.reserve(N);
	cin >> TC;
	while (TC--) {
		ans = INT_MAX;
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a.emplace_back();
		if (n == 2) {
			cout << max(a[1] - a[0], a[0] - a[1]) << '\n';
			goto cleanup;
		} else if (n == 3) {
			cout << max({ a[0], a[1] - a[0] - a[2], a[2] }) << '\n';
			goto cleanup;
		}
		ans = INT_MIN;
		for (int i = 0; i < n; ++i) {
			if (i == 1) ans = max(ans, a[1] - a[0]);
			if (i == n - 2) ans = max(ans, a[n - 2] - a[n - 1]);
			if (i != 1 && i != n - 2) ans = max(ans, a[i]);
		}
		cout << ans << '\n';
cleanup:
		a.clear();
	}
}
