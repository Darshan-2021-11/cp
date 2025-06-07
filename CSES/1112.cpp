#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int MOD = 1e9 + 7;
	int64_t sum, t;
	int n, m;
	char s[100];
	scanf("%d\n%s\n", &n, s);
	m = strlen(s);

	if (n < m) {
		putchar('0');
		return 0;
	} else if (n == m) {
		putchar('1');
		return 0;
	}

	int dp[1001][2][26];
	for (int i = 0; i < 26; ++i)
		dp[0][0][i] = dp[0][1][i] = 0;
	dp[0][0][0] = 1;
	for (int j = 1; j <= n; ++j) {
		sum = 0;
		printf("%d:\n", j);
		for (int i = 0; i < 26; ++i) sum += dp[j - 1][0][i];
		sum %= MOD;
		for (int i = 0; i < 26; ++i) {
			if (j >= m && i == s[m - 1] - 'A') {
				t = dp[j - m + 1][0][s[0] - 'A'];
				dp[j][0][i] = ((sum - t) % MOD + MOD) % MOD;
			} else dp[j][0][i] = sum;
			printf("%d ", dp[j][0][i]);
		}
		putchar('\n');

		sum = 0;
		for (int i = 0; i < 26; ++i) sum += dp[j - 1][1][i];
		sum %= MOD;
		for (int i = 0; i < 26; ++i) {
			if (j >= m && i == s[m - 1] - 'A') {
				dp[j][1][i] = (sum + t) % MOD;
			} else dp[j][1][i] = sum;
			printf("%d ", dp[j][1][i]);
		}
		putchar('\n');
	}

	sum = 0;
	for (int i = 0; i < 26; ++i) {
		sum += dp[n][1][i];
	}
	printf("%lld", sum % MOD);
}
