#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 1000;
	int64_t a[N][N], r[N], c[N], sum;
	int TC = 1, n, m, idx, x, y;
	char b[N << 1];
	cin >> TC;
	while (TC--) {
		cin >> n >> m;
		cin >> b;
		for (int i = 0; i < m; ++i) c[i] = 0;
		for (int i = 0; i < n; ++i) {
			r[i] = 0;
			for (int j = 0; j < m; ++j) {
				cin >> a[i][j];
				r[i] += a[i][j];
				c[j] += a[i][j];
			}
		}
		idx = x = y = 0;
		do {
			if (b[idx] == 'D') {
				a[x][y] = 0 - r[x];
				c[y] += a[x][y];
				r[x] += a[x][y];
				++x;
			} else {
				a[x][y] = 0 - c[y];
				c[y] += a[x][y];
				r[x] += a[x][y];
				++y;
			}
			++idx;
		} while (x != n - 1 || y != m - 1);
		a[x][y] = 0 - r[x];

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
	}
}
