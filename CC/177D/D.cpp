#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 2000;
	int TC = 1, n, cntdiff, an, ans[N];
	bool swap;
	char a[N], b[N];
	cin >> TC;
	while (TC--) {
		swap = false;
		cntdiff = an = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> b[i];
		for (int i = 0; i < n; ++i) {
			cntdiff += a[i] != b[i];
		}
		if (cntdiff > ((n + 1) >> 1)) {
			swap = true;
		}
		for (int i = 0; i < n; ++i) {
			if ((a[i] != b[i]) ^ swap) ans[an++] = i + 1;
		}
		cout << swap + an << '\n';
		if (swap) {
			cout << 1 << ' ' << 1 << ' ' << n << '\n';
		}
		for (int i = 0; i < an; ++i)
			cout << 1 << ' ' << ans[i] << ' ' << ans[i] << '\n';
	}
}
