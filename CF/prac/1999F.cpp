#include <bits/stdc++.h>
using namespace std;

const int N = 200'001, MOD = 1e9 + 7;

int modinv(int a) {
  return a <= 1 ? a : MOD - (int64_t)(MOD/a) * modinv(MOD % a) % MOD;
}

int64_t nck(int *f, int n, int k) {
	int64_t res = f[n];
	(res *= modinv(f[k])) %= MOD;
	(res *= modinv(f[n - k])) %= MOD;
	return res;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n, k, cnt1, ans, f[N];
	f[0] = 1;
	for (int64_t i = 1; i < N; ++i)
		f[i] = f[i - 1] * i % MOD;
	cin >> TC;
	while (TC--) {
		cnt1 = ans = 0;
		cin >> n >> k;
		for (int i = 0, a; i < n; ++i) cin >> a, cnt1 += a;
		if ((k + 1 >> 1) > cnt1) goto print;
		for (int i = min(k >> 1, n - cnt1); ~i; --i) {
			if (k - i > cnt1) break;
			ans += (nck(f, cnt1, k - i) * nck(f, n - cnt1, i) % MOD);
			if (ans > MOD) ans -= MOD;
		}
print:
		cout << ans << '\n';
	}
}
