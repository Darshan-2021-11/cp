#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'001;
	int TC = 1, n, k, x, lg, a[N], b[N], up[N][19];
	bool yes;
	cin >> TC;
	while (TC--) {
		yes = true;
		cin >> n >> k >> x;
		--x;
		for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
		for (int i = 0; i < n; ++i) cin >> b[i], --b[i];

		lg = 32 - __builtin_clz(n);
		for (int i = 0; i < n; i++) {
			up[i][0] = a[i];
		}
		for (int j = 1; j < lg; j++) {
			for (int i = 0; i < n; i++) {
				if (up[i][j - 1] == -2) up[i][j] = -2;
				else up[i][j] = up[up[i][j-1]][j-1];
			}
		}
		for (int i = 1; i <= k; i++) {
			int back = k - i + 1;
			for (int j = lg - 1; j >= 0; j--) {
				if (back >= (1 << j)) {
					x = up[x][j];
					back -= (1 << j);
				}
				if (x == -2) {
					yes = false;
					break;
				}
			}
			if (!yes) {
				break;
			}
			x = b[x];
			if (x == -2) {
				yes = false;
				break;
			}
		}
		if (!yes) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
