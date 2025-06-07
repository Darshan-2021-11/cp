#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 100'000, MOD = 1e9 + 7, MOD_M1 = MOD - 1;
	int64_t cnt, sum, prd;
	int TC = 1, n, a[N][2];
	const auto modinv = [&MOD](const auto &rec, int num) -> int {
		return num <= 1 ? num : MOD - static_cast<int64_t>(MOD / num) * rec(rec, MOD % num) % MOD;
	};
	const auto binpow = [&MOD](int64_t num, int64_t p) -> int64_t {
		num %= MOD;
		int64_t res = 1;
		while (p > 0) {
			if (p & 1)
				res = res * num % MOD;
			num = num * num % MOD;
			p >>= 1;
		}
		return res;
	};
	//cin >> TC;
	while (TC--) {
		cnt = sum = prd = 1;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> a[i][0] >> a[i][1],
			(cnt *= a[i][1] + 1) %= MOD,
			(sum *= ((binpow(a[i][0], a[i][1] + 1) + MOD - 1) % MOD * modinv(modinv, a[i][0] - 1)) % MOD) %= MOD;
		cout << cnt << ' ' << sum << ' ';

	}
}
