#include <bits/stdc++.h>
using namespace std;

template<int SIZE>
struct bs {
	static const uint32_t IDX_RS = 5;
	static const uint32_t MASK = (sizeof(uint32_t) << 3) - 1;
	uint32_t data[(SIZE + MASK) >> IDX_RS];
	void init(int n) noexcept {
		fill_n(data, (n + MASK) >> IDX_RS, 0);
	}
	void set(int idx) noexcept {
		data[idx >> IDX_RS] |= (1U << (idx & MASK));
	}
	void reset(int idx) noexcept {
		data[idx >> IDX_RS] &= ~(1U << (idx & MASK));
	}
	void flip(int idx) noexcept {
		data[idx >> IDX_RS] ^= (1U << (idx & MASK));
	}
	uint32_t get(int64_t idx) const noexcept {
		if (idx < 0 || idx >= SIZE) return 0U;
		return (data[idx >> IDX_RS] >> (idx & MASK)) & 1U;
	}
};

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000, zero = N;
	int64_t k, sa, sb, f1, f2;
	int TC = 1, n, m, q, a[N], b[N];
	bool yes;
	bs<(N << 1) + 1> ma, mb;

	ma.init((N << 1) + 1), mb.init((N << 1) + 1);

	while (TC--) {
		sa = sb = zero;

		cin >> n >> m >> q;
		for (int i = 0; i < n; ++i) cin >> a[i], sa += a[i], ma.set(a[i] + zero);
		for (int i = 0; i < m; ++i) cin >> b[i], sb += b[i], mb.set(b[i] + zero);

		while (q--) {
			yes = false;
			cin >> k;

			for (int64_t i = 1; i * i <= abs(k); ++i) {
				if (k % i) continue;
				f1 = i, f2 = k / i;
				if (
						(ma.get(sa - f1) && mb.get(sb - f2)) ||
						(ma.get(sa + f1) && mb.get(sb + f2)) ||
						(ma.get(sa - f2) && mb.get(sb - f1)) ||
						(ma.get(sa + f2) && mb.get(sb + f1))
					 ) {
					yes = true;
					break;
				}
			}
			cout << (yes ? "YES\n" : "NO\n");
		}

		for (int i = 0; i < n; ++i) ma.reset(a[i] + zero);
		for (int i = 0; i < m; ++i) mb.reset(b[i] + zero);
	}
}
