#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int MOD = 1e9 + 7, N = 1e6 + 1;
	const auto inv = [&](const auto &rec, int a) -> int {
		return a <= 1 ? a : MOD - (long long)(MOD / a) * rec(rec, MOD % a) % MOD;
	};
	const int MODINV2 = inv(inv, 2);
	int64_t ans, n, i;
	int TC = 1, a[N];
	//cin >> TC;
	while (TC--) {
		ans = 0;
		cin >> n;
		for (i = 1; i * i <= n; ++i)
			(ans += (a[i] = n / i % MOD) * i % MOD) %= MOD;
		--i;
		if (a[i] != i)
			(ans += ((static_cast<int64_t>(i + 1 + a[i]) % MOD * ((a[i] - i) % MOD + MOD) % MOD) % MOD * MODINV2 % MOD) * i % MOD) %= MOD;
		while (i-- > 1)
			(ans += ((static_cast<int64_t>(a[i + 1] + 1 + a[i]) % MOD * ((a[i] - a[i + 1]) % MOD + MOD) % MOD) % MOD * MODINV2 % MOD) * i % MOD) %= MOD;
		cout
			<< ans
			<< '\n';
	}
}
