#include <bits/stdc++.h>
using namespace std;

namespace {
	template <int SIZE> struct bs {
		static const uint32_t IDX_RS = 5;
		static const uint32_t MASK = (sizeof(uint32_t) << 3) - 1;
		uint32_t data[(SIZE + MASK) >> IDX_RS];
		void init(uint32_t n, bool val = false) { fill_n(data, (n + MASK) >> IDX_RS, val ? UINT32_MAX : 0); }
		void set(uint32_t idx) { data[idx >> IDX_RS] |= (1U << (idx & MASK)); }
		void reset(uint32_t idx) { data[idx >> IDX_RS] &= ~(1U << (idx & MASK)); }
		void flip(uint32_t idx) { data[idx >> IDX_RS] ^= (1U << (idx & MASK)); }
		void assign(uint32_t idx, bool val) { val ? set(idx) : reset(idx); }
		uint32_t get(uint32_t idx) { return (data[idx >> IDX_RS] >> (idx & MASK)) & 1U; }
	};
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	bs<N> b;
	int TC = 1, st[N << 2], mp[N << 1], s[N], q[N][2], un, n, m;
	char c;
	//cin >> TC;
	while (TC--) {
		cin >> n >> m;
		un = n, b.init(n);
		for (int i = 0; i < n; ++i) cin >> s[i], mp[i] = s[i];
		for (int i = 0, t; i < m; ++i)
			cin >> c >> q[i][0] >> q[i][1];
		if (c == '?') b.assign(i, true), mp[un++] = q[i][1];
		sort(mp, mp + un);
		un = unique(mp, mp + un) - mp;
		fill_n(st, un << 1, 0);
		for (int i = 0; i < n; ++i) ++st[(lower_bound(mp, mp + un, s[i]) - mp) + un];
		for (int i = un - 1; i; --i) st[i] += st[i << 1] + st[i << 1 | 1];
		for (int i = 0, t; i < m; ++i) {
			if (b.get(i)) {
				for (int l = lower_bound(mp, mp + un, q[i][0])
			} else {
			}
		}
	}
}
