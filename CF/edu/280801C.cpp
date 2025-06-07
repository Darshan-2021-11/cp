#include <bits/stdc++.h>
using namespace std;

namespace {
	template <int SIZE> struct bs {
		static const uint32_t IDX_RS = 5;
		static const uint32_t MASK = (sizeof(uint32_t) << 3) - 1;
		uint32_t data[(SIZE + MASK) >> IDX_RS];
		void init(uint32_t n, bool val) { fill_n(data, (n + MASK) >> IDX_RS, val ? UINT32_MAX : 0); }
		void set(uint32_t idx) { data[idx >> IDX_RS] |= (1U << (idx & MASK)); }
		void reset(uint32_t idx) { data[idx >> IDX_RS] &= ~(1U << (idx & MASK)); }
		void flip(uint32_t idx) { data[idx >> IDX_RS] ^= (1U << (idx & MASK)); }
		void assign(uint32_t idx, bool val) { val ? set(idx) : reset(idx); }
		uint32_t get(uint32_t idx) { return (data[idx >> IDX_RS] >> (idx & MASK)) & 1U; }
	};
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const uint32_t N = 1'000'001, O = 500'000, h = 32 - __builtin_clz(N);
	uint32_t st[N << 1], le[N << 1], lz[N], v, q, l, r, l0, r0;
	bs<(N << 1)> lb, rb;
	char c;

	const auto app = [&st, &lz, &le, &lb, &rb, &h, &N](uint32_t idx) -> void {
		idx += N;
		uint32_t t = h, u;
		do {
			u = idx >> t;
			if (lz[u] != UINT32_MAX) {
				if ((u << 1) < N) lz[u << 1] = lz[u];
				if ((u << 1 | 1) < N) lz[u << 1 | 1] = lz[u];
				if (lz[u]) {
					lb.set(u << 1), rb.set(u << 1), lb.set(u << 1 | 1), rb.set(u << 1 | 1);
					le[u << 1] = le[u << 1 | 1] = le[u] >> 1, st[u << 1] = st[u << 1 | 1] = 1;
				} else {
					lb.reset(u << 1), rb.reset(u << 1), lb.reset(u << 1 | 1), rb.reset(u << 1 | 1);
					le[u << 1] = st[u << 1] = le[u << 1 | 1] = st[u << 1 | 1] = 0;
				}
				lz[u] = UINT32_MAX;
			}
		} while (--t);
	};
	const auto upd = [&st, &le, &lz, &rb, &lb, &v, &N](uint32_t idx) -> void {
		idx += N, v = 1;
		while (v <<= 1, idx >>= 1) {
			if (lz[idx] != UINT32_MAX) {
				if (lz[idx]) le[idx] = v, st[idx] = 1;
				else le[idx] = st[idx] = 0;
			} else {
				st[idx] = st[idx << 1] + st[idx << 1 | 1] - (rb.get(idx << 1) & lb.get(idx << 1 | 1)), le[idx] = le[idx << 1] + le[idx << 1 | 1];
				lb.assign(idx, lb.get(idx << 1));
				rb.assign(idx, rb.get(idx << 1 | 1));
			}
		}
	};
	const auto query = [&st, &le, &lz, &rb, &lb, &N, &app, &v](uint32_t li, uint32_t ri) -> array<uint32_t, 2> {
		// required for generic range instead of full range
		//app(li), app(ri - 1);
		li += N + O, ri += N + O, v = 1;
		uint32_t stv[2]{}, lev[2]{}, rbv{}, lbv{};
		if (li & 1) stv[0] = st[li], lev[0] = le[li], rbv = rb.get(li), ++li;
		if (ri & 1) --ri, stv[1] = st[ri], lev[1] = le[ri], lbv = lb.get(ri);
		while (v <<= 1, (li >>= 1) < (ri >>= 1)) {
			if (li & 1) {
				if (lz[li] != UINT32_MAX) {
					if (lz[li]) lev[0] += v, stv[0] += 1 - rbv, rbv = 1;
					else rbv = 0;
				} else lev[0] += le[li], stv[0] += st[li] - (rbv & lb.get(li)), rbv = rb.get(li);
				++li;
			}
			if (ri & 1) {
				--ri;
				if (lz[ri] != UINT32_MAX) {
					if (lz[ri]) lev[1] += v, stv[1] += 1 - lbv, lbv = 1;
					else lbv = 0;
				} else lev[1] += le[ri], stv[1] += st[ri] - (lbv & rb.get(ri)), lbv = lb.get(ri);
			}
		}
		return { stv[0] + stv[1] - (lbv & rbv), lev[0] + lev[1] };
	};

	cin >> q;
	fill_n(st, N << 1, 0);
	fill_n(le, N << 1, 0);
	fill_n(lz, N, UINT32_MAX);
	lb.init(N << 1, false);
	rb.init(N << 1, false);

	while (q--) {
		cin >> c >> l >> r;
		r += l, l += O, r += O, l0 = l, r0 = r, l += N, r += N, c = c == 'B';
		app(l0), app(r0 - 1);
		if (c) {
			v = 1;
			if (l & 1) lb.set(l), rb.set(l), le[l] = st[l] = 1, ++l;
			if (r & 1) --r, lb.set(r), rb.set(r), le[r] = st[r] = 1;
			while (v <<= 1, (l >>= 1) < (r >>= 1)) {
				if (l & 1) lb.set(l), rb.set(l), le[l] = v, st[l] = lz[l] = 1, ++l;
				if (r & 1) --r, lb.set(r), rb.set(r), le[r] = v, st[r] = lz[r] = 1;
			}
		} else {
			if (l & 1) lb.reset(l), rb.reset(l), le[l] = st[l] = 0, ++l;
			if (r & 1) --r, lb.reset(r), rb.reset(r), le[r] = st[r] = 0;
			while ((l >>= 1) < (r >>= 1)) {
				if (l & 1) lb.reset(l), rb.reset(l), le[l] = st[l] = lz[l] = 0, ++l;
				if (r & 1) --r, lb.reset(r), rb.reset(r), le[r] = st[r] = lz[r] = 0;
			}
		}
		upd(l0), upd(r0 - 1);
		/*
			 cout << "st:\n";
			 for (uint32_t i = 1; i < N << 1; ++i) {
			 cout << st[i] << ' ';
			 if (!(i & (i + 1))) cout << '\n';
			 }
			 cout << "\nle:\n";
			 for (uint32_t i = 1; i < N << 1; ++i) {
			 cout << le[i] << ' ';
			 if (!(i & (i + 1))) cout << '\n';
			 }
			 cout << "\nlz:\n";
			 for (uint32_t i = 1; i < N; ++i) {
			 cout << lz[i] << ' ';
			 if (!(i & (i + 1))) cout << '\n';
			 }
			 cout << '\n';
			 cout << "res: ";
		*/
		array<uint32_t, 2> res = query(-500'000, 500'000);
		cout << res[0] << ' ' << res[1] << '\n';
	}
}
