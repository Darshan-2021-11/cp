#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'001, MOD = 998244353;
	int TC = 1, n;
	int64_t dp[N][2], ans;
	cin >> TC;
	while (TC--) {
		ans = 0;
		cin >> n;
		dp[0][0] = 0;
		dp[0][1] = 0;
		for (int i = 1, t; i <= n; ++i) {
			cin >> t;
			if (t == 1) {
				dp[i][0] = dp[i - 1][0] + 1;
				dp[i][1] = dp[i - 1][1];
			} else if (t == 2) {
				dp[i][0] = dp[i - 1][0];
				(dp[i][1] = (dp[i - 1][1] << 1) + dp[i - 1][0]) %= MOD;
			} else {
				dp[i][0] = dp[i - 1][0];
				dp[i][1] = dp[i - 1][1];
				(ans += dp[i][1]) %= MOD;
			}
		}
		cout << ans << '\n';
	}
}
