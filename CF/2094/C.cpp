#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 800;
	int TC = 1, n, a[N][N], f[(N << 1) + 1], x;
	cin >> TC;
	while (TC--) {
		cin >> n;
		for (int i = 1; i <= n * 2; ++i) f[i] = false;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) cin >> a[i][j], f[a[i][j]] = true;
		}
		x = -1;
		for (int i = 1; i <= n * 2; ++i) if (!f[i]) x = i;
		assert(x != -1);
		cout << x << ' ';
		for (int i = 0; i < n; ++i) cout << a[0][i] << ' ';
		for (int j = 1; j < n; ++j) cout << a[j][n - 1] << ' ';
		cout << '\n';
	}
}
