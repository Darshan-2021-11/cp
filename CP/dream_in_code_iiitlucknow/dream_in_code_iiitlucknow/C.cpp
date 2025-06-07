#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int64_t binpow(int64_t a, int64_t b) {
	a %= M;
	int64_t res = 1;
	while (b > 0) {
		if (b & 1)
			(res *= a) %= M;
		(a *= a) %= M;
		b >>= 1;
	}
	return res;
}

int64_t inv(const int64_t a) {
	return a <= 1 ? a : M - (int64_t)(M/a) * inv(M % a) % M;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 1'000'005;
	int64_t t, u, bm1inv, bm1inv2;
	int TC = 1, h, b[N];
	b[0] = 1;
	const auto agp = [&](int64_t a, int64_t d, int64_t n) -> int64_t {
		if (n == 0) return 0;
		int64_t rn = b[n];     // r^n
		int64_t rnm1 = b[n-1]; // r^(n-1)

		int64_t term1 = (a % M) * (rn - 1 + M) % M;
		term1 = term1 * bm1inv % M;

		int64_t term2_part = (1 % M - (n % M) * rnm1 % M + ((n - 1) % M) * rn % M) % M;
		term2_part = (term2_part + M) % M;

		int64_t term2 = (d % M) * b[1] % M;
		term2 = term2 * term2_part % M;
		term2 = term2 * bm1inv2 % M;

		int64_t total = (term1 + term2) % M;
		return total;
	};
	cin >> TC;
	while (TC--) {
		cin >> t >> h;
		b[1] = t;
		if (h == 1) {
			cout << max(b[1] - 2, 0) << '\n';
			continue;
		}
		if (b[1] == 1) {
			cout << 0 << '\n';
			continue;
		}
		bm1inv = inv(b[1] - 1);
		bm1inv2 = bm1inv * bm1inv % M;
		for (int i = 2; i <= h; ++i) {
			b[i] = (t * b[1]) % M;
		}
		t = (b[1] - 2) * agp(1, 1, h - 1) % M;
		for (int i = 1; i < h; ++i) {
			u = agp(1, 1, h - i);
			u = ((b[1] - 1) * u % M) * 2 % M;
			(t += u) %= M;
		}
		cout << t << '\n';
	}
}
