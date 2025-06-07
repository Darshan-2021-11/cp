#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'001;
	int64_t a[N << 1], b[N << 1];
	int TC = 1, n, k, mx;
	a[0] = b[0] = 0;
	cin >> TC;
	while (TC--) {
		mx = 1;
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) cin >> a[i], a[i + n] = a[i];
		for (int i = 1; i <= n; ++i) cin >> b[i], b[i + n] = b[i];
		partial_sum(a, a + (n << 1) + 1, a);
		partial_sum(b, b + (n << 1) + 1, b);
		for (int i = 1, l, r, x; i <= n; ++i) {
			l = 0, r = n + 1;
			while (l < r) {
				x = l + r >> 1;
				if (a[i + x] - a[i] > b[i + x] - b[i]) l = x + 1;
				else r = x;
			}
			mx = max(mx, l);
		}
		cout << mx << '\n';
	}
}
