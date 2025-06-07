#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'001;
	int TC = 1, n, m, x, ans, a[N], b[N], sf[N];
	cin >> TC;
	while (TC--) {
		ans = INT_MAX;
		cin >> n >> m;
		x = 0;
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < m; ++i) cin >> b[i];
		for (int i = n - 1; ~i; --i) {
			if (x < m && a[i] >= b[m - 1 - x]) ++x;
			sf[i] = x;
		}
		x = 0;
		for (int i = 0; i < n; ++i) {
			if (x + sf[i] == m) {
				ans = 0;
			} else if (x + sf[i] == m - 1) {
				ans = min(ans, b[x]);
			}
			if (x < m && a[i] >= b[x]) ++x;
		}
		if (x == m - 1) ans = min(b[m - 1], ans);
		cout << (ans == INT_MAX ? -1 : ans) << '\n';
	}
}
