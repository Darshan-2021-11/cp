#include <bits/stdc++.h>
using namespace std;

static int64_t binpow(int64_t a, int64_t b, const int64_t MOD) {
	int64_t res = 1;
	while (b) {
		if (b & 1) (res *= a) %= MOD;
		(a *= a) %= MOD;
		b >>= 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 250'001, MOD = 998'244'353;
	int64_t ans, f[N], f_inv[N];
	int TC = 1, dp[N], a[26], t, sum;
	f[0] = f_inv[0] = 1;
	for (int i = 1; i < N; ++i) f[i] = i * f[i - 1] % MOD;
	f_inv[N - 1] = binpow(f[N - 1], MOD - 2, MOD);
	for (int i = N - 2; i; --i) f_inv[i] = f_inv[i + 1] * (i + 1) % MOD;
	bool pos;
	dp[0] = 1;
	cin >> TC;
	while (TC--) {
		ans = sum = 0, pos = true;
		for (int i = 0; i < 26; ++i) cin >> a[i], sum += a[i];
		t = (sum + 1) >> 1;
		for (int i = 0; i < 26; ++i) pos &= a[i] <= t;

		if (!pos) {
			cout << 0 << '\n';
			continue;
		}

		fill_n(dp + 1, t + 1, 0);

		for (int i = 0; i < 26; ++i) {
			if (!a[i]) continue;
			for (int j = t - a[i]; j >= 0; --j) {
				if (!dp[j]) continue;
				dp[j + a[i]] += dp[j];
				if (dp[j + a[i]] >= MOD)
					dp[j + a[i]] -= MOD;
			}
		}

		ans = ((dp[t] * f[t] % MOD) * f[sum >> 1]) % MOD;
		for (int i = 0; i < 26; ++i) {
			if (!a[i]) continue;
			(ans *= f_inv[a[i]]) %= MOD;
		}
		cout << ans << '\n';
	}
}
