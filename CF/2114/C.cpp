#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'001;
	int TC = 1, n, a[N], dp[N][2][2];
	cin >> TC;
	while (TC--) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		dp[0][0][0] = 0, dp[0][0][1] = -1;
		dp[0][1][0] = 0, dp[0][1][1] = -1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 2; ++j) {
				if (dp[i][j][1] + 1 < a[i]) {
					dp[i + 1][j][0] = dp[i][j][0] + 1;
					dp[i + 1][j][1] = a[i];
				} else {
					dp[i + 1][j][0] = dp[i][j][0];
					dp[i + 1][j][1] = dp[i][j][1];
				}
			}
		}
		cout << max(dp[n][0][0], dp[n][1][0]) << '\n';
	}
}
