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
	const int N = 500'000;
	int64_t ans, u;
	int TC = 1, n, a[N], t, x;
	bs<N> b;
	multiset<int64_t> m;
	cin >> TC;
	while (TC--) {
		ans = 0;
		cin >> n;
		b.init(n);
		for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
		for (int i = 0; i < n; ++i) cout << a[i] << ' ';
		cout << '\n';
		for (int i = 0; i < n; ++i) if (!b.get(i)) {
			t = 1, x = a[i];
			while (x != i) b.set(x), x = a[x], ++t;
			b.set(i);
			m.insert(t);
		}
		while (m.size() > 1) {
			u = *m.begin();
			m.erase(m.begin());
			u += *m.begin();
			m.erase(m.begin());
			ans += u;
			m.insert(u);
		}
		cout << ans << '\n';
		m.clear();
	}
}
