#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000, MOD = 998244353;
	const auto modinv = [&](int64_t a) -> int {
		int64_t b = MOD - 2, res = 1;
		while (b) {
			if (b & 1) (res *= a) %= MOD;
			(a *= a) %= MOD;
			b >>= 1;
		}
		return res;
	};
	int TC = 1, n, q, x, a[N], b[N], c[N], d[N];
	int64_t ans;
	cin >> TC;
	while (TC--) {
		ans = 1;
		cin >> n >> q;
		for (int i = 0; i < n; ++i) cin >> a[i], c[i] = a[i];
		for (int i = 0; i < n; ++i) cin >> b[i], d[i] = b[i];
		sort(c, c + n);
		sort(d, d + n);
		for (int i = 0; i < n; ++i)
			(ans *= min(c[i], d[i])) %= MOD;
		cout << ans << ' ';
		while (q--) {
			int t, u;
			cin >> t >> u;
			--u;
			if (t == 1) {
				++a[u];
				x = lower_bound(c, c + n, a[u]) - c - 1;
				(ans *= modinv(min(c[x], d[x]))) %= MOD;
				++c[x];
				(ans *= min(c[x], d[x])) %= MOD;
			} else {
				++b[u];
				x = lower_bound(d, d + n, b[u]) - d - 1;
				(ans *= modinv(min(c[x], d[x]))) %= MOD;
				++d[x];
				(ans *= min(c[x], d[x])) %= MOD;
			}
			cout << ans << ' ';
		}
		cout << '\n';
	}
}
