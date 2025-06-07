#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 31;
	int TC = 1, n, a[N][2];
	char op[N][2];
	int64_t dp[3];
	cin >> TC;
	while (TC--) {
		cin >> n;
		for (int i = 0; i < n; ++i) for (int j = 0; j < 2; ++j) {
			cin >> op[i][j] >> a[i][j];
			if (op[i][j] == 'x') --a[i][j];
		}
		dp[0] = dp[1] = 1, dp[2] = 0;
		for (int i = 0; i < n; ++i) {
			if (op[i][0] == 'x' && op[i][1] == 'x') {
				if (a[i][0] == a[i][1]) {
					dp[2] += (dp[2] + dp[0] + dp[1]) * a[i][1];
				} else if (a[i][0] > a[i][1]) {
					dp[0] += dp[2];
					dp[2] = dp[0] * a[i][0] + dp[1] * a[i][1];
				} else {
					dp[1] += dp[2];
					dp[2] = dp[1] * a[i][1] + dp[0] * a[i][0];
				}
			} else if (op[i][0] == 'x') {
				dp[0] += dp[2];
				dp[2] = dp[0] * a[i][0];
				dp[2] += a[i][1];
			} else if (op[i][1] == 'x') {
				dp[1] += dp[2];
				dp[2] = dp[1] * a[i][1];
				dp[2] += a[i][0];
			} else {
				dp[2] += a[i][0] + a[i][1];
			}
		}
		cout << dp[0] +  dp[1] + dp[2] << '\n';
	}
}
