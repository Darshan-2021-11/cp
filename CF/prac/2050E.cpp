#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 1'001;
	int TC = 1, dp[N][N], an, bn, cn;
	char a[N], b[N], c[N << 1];
	cin >> TC;
	while (TC--) {
		cin >> a >> b >> c;
		an = strlen(a), bn = strlen(b), cn = an + bn;
		dp[0][0] = 0;
		for (int i = 0; i < cn; ++i) {
			for (int j = min(i, an), k = i - j; k <= bn && ~j; --j, ++k) {
				if (j < an) dp[j + 1][k] = INT_MAX;
				if (k < bn) dp[j][k + 1] = INT_MAX;
			}
		}
		for (int i = 0; i < cn; ++i) {
			for (int j = min(i, an), k = i - j; k <= bn && ~j; --j, ++k) {
				if (j < an) dp[j + 1][k] = min(dp[j][k] + (a[j] != c[i]), dp[j + 1][k]);
				if (k < bn) dp[j][k + 1] = min(dp[j][k] + (b[k] != c[i]), dp[j][k + 1]);
			}
		}
		cout << dp[an][bn] << '\n';
	}
}
