#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, n, a[N], f, x, d[2];
	cin >> TC;
	while (TC--) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		f = a[0];
		sort(a, a + n);
		x = lower_bound(a, a + n, f) - a;
		if (x == 0) {
			d[0] = a[1] - a[0] - 1;
			d[0] = (d[0] >> 1) + (d[0] & 1);
			cout << a[0] - 0 + d[0] << '\n';
		} else if (x == n - 1) {
			d[0] = a[n - 1] - a[n - 2] - 1;
			d[0] = (d[0] >> 1) + (d[0] & 1);
			cout << 1'000'001 - a[n - 1] + d[0] << '\n';
		} else {
			d[0] = a[x] - a[x - 1] - 1;
			d[0] = (d[0] >> 1) + (d[0] & 1);
			d[1] = a[x + 1] - a[x] - 1;
			d[1] = (d[1] >> 1) + (d[1] & 1);
			cout << d[0] + d[1] + 1 << '\n';
		}
	}
}
