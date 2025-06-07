#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 300'001;
	int TC = 1, n, k, a[N], b[N], bn, mx, l, r, x, part;
	char c[N], clr;
	bool s;
	cin >> TC;
	while (TC--) {
		bn = 0;
		cin >> n >> k;
		for (int i = 0; i < n; ++i) cin >> c[i];
		for (int i = 0; i < n; ++i) cin >> a[i];
		bn = (clr = c[0]) == 'B';
		if (bn) b[bn - 1] = 0;
		mx = a[0];
		for (int i = 1; i < n; ++i) {
			if (clr != c[i])
				b[bn++] = mx, clr = c[i], mx = a[i];
			else mx = max(mx, a[i]);
		}
		b[bn++] = mx;

		if ((bn >> 1) <= k) {
			cout << 0 << '\n';
			continue;
		}
		l = 0, r = 1e9 + 1;
		while (l < r) {
			part = 0, s = false;
			x = l + r >> 1;
			for (int i = 0; i < bn; ++i) {
				if (b[i] >= x) {
					if (i & 1) s = true;
					else part += s, s = false;
				}
			}
			part += s;
			if (part > k) l = x + 1;
			else r = x;
		}
		mx = INT_MIN, s = false;
		for (int i = 0; i < bn; ++i) {
			if (b[i] >= l) {
				if (i & 1) s = true;
				else s = false;
			} else mx = max(mx, b[i]);
		}
		cout << mx << '\n';
	}
}
