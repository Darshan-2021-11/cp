#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 51;
	int TC = 1, n, ans, a[N], mn[2], mx[2];
	cin >> TC;
	while (TC--) {
		ans = INT_MAX;
		cin >> n;
		fill_n(a, N, 0);
		fill_n(mn, 2, INT_MAX);
		fill_n(mx, 2, INT_MIN);
		for (int i = 0, t; i < n; ++i) {
			cin >> t, ++a[t];
			mn[t & 1] = min(mn[t & 1], t);
			mx[t & 1] = max(mx[t & 1], t);
		}
		for (int i = 0, t; i < 2; ++i) {
			t = 0;
			for (int j = mn[i]; j <= mx[i]; ++j)
				t += a[j];
			ans = min(n - t, ans);
		}
		cout << ans << '\n';
	}
}
