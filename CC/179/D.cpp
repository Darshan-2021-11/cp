#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'002;
	int64_t ans, t, prev;
	int TC = 1, n, a[N], l1, r1, l2, r2, x;
	a[0] = 0;
	cin >> TC;
	while (TC--) {
		ans = prev = 0;
		ans = 0;
		cin >> n;
		a[n + 1] = 0;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		for (int i = 1; i <= n; ++i) {
			if ((a[i] <= a[i + 1] && a[i - 1] < a[i]) || (a[i] < a[i - 1] && a[i + 1] < a[i])) continue;
			l1 = 1, r1 = i;
			while (l1 < r1) {
				x = l1 + r1 >> 1;
				if (abs(a[i] - a[x]) == i - x) r1 = x;
				else l1 = x + 1;
			}
			l2 = i, r2 = n + 1;
			while (l2 < r2) {
				x = l2 + r2 >> 1;
				if (abs(a[i] - a[x]) == x - i) l2 = x + 1;
				else r2 = x;
			}
			t = l2 - l1;
			ans += ((t * (t - 1)) >> 1) - prev;
			t = l2 - i;
			prev = (t * (t - 1)) >> 1;
		}
		cout << ans << '\n';
	}
}
