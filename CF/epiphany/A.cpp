#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 2005;
	int TC = 1, n, v, dp[N << 1][N << 1], lcs[N << 1][2], lcsn;
	char a[N << 1], b[N << 1];
	while (TC--) {
		lcsn = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i], a[i + n] = a[i];
		for (int i = 0; i < n; ++i) cin >> b[i], b[i + n] = b[i];
		n <<= 1;
		for (int i = 0; i <= n; ++i) dp[0][i] = dp[i][0] = 0;
		for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
			if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
		int ans = 0;
		lcsn = dp[n][n] - 1;
		int x = n, y = n;
		while (x > 0 && y > 0) {
			if (a[x - 1] == b[y - 1]) {
				lcs[lcsn][0] = x - 1, lcs[lcsn][1] = y - 1;
				--lcsn, --x, --y;
			} else if (dp[x - 1][y] > dp[x][y - 1]) --x;
			else --y;
		}
		/*
		for (int i = 0; i < dp[n][n]; ++i) {
			cout << a[lcs[i][0]];
		}
		cout << '\n';
		for (int i = 0; i < dp[n][n]; ++i) {
			cout << lcs[i][0] << ',' << lcs[i][1] << ' ';
		}
		cout << '\n';
		*/
		v = n >> 1;
		for (int i = 0; i < dp[n][n]; ++i) {
			for (int j = dp[n][n] - 1; j > i; --j) {
				if (lcs[j][0] - lcs[i][0] < v && lcs[j][1] - lcs[i][1] < v) {
					//cout << i << ' ' << j << '\n';
					ans = max(ans, j - i + 1);
					break;
				}
			}
		}
		cout << ans << '\n';
	}
}
