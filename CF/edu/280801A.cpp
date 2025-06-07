#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 100'000;
	uint64_t st[N << 1], lz[N], in[N], v, res;
	int n, m, h, l, r, l0, r0, t;

	static const auto app = [&st, &lz, &in, &h, &n] (int idx) {
		int a = h, b;
		idx += n;
		while (--a) {
			b = idx >> a;
			if (lz[b] != UINT64_MAX) {
				lz[b] >>= 1, in[b] >>= 1;
				st[b << 1] = st[b << 1 | 1] = lz[b] + in[b];
				if ((b << 1) < n) lz[b << 1] = lz[b], in[b << 1] = in[b];
				if ((b << 1 | 1) < n) lz[b << 1 | 1] = lz[b], in[b << 1 | 1] = in[b];
				lz[b] = UINT64_MAX, in[b] = 0;
				continue;
			}
			if (in[b]) {
				in[b] >>= 1;
				st[b << 1] += in[b], st[b << 1 | 1] += in[b];
				if ((b << 1) < n) in[b << 1] += in[b];
				if ((b << 1 | 1) < n) in[b << 1 | 1] += in[b];
				in[b] = 0;
			}
		}
	};

	static const auto upd = [&st, &lz, &in, &n] (int idx) {
		idx += n;
		while (idx >>= 1) {
			if (lz[idx] != UINT64_MAX) st[idx] = lz[idx] + in[idx];
			else st[idx] = st[idx << 1] + st[idx << 1 | 1] + in[idx];
		}
	};

	cin >> n >> m;

	h = (sizeof(int) << 3) - __builtin_clz(n);
	fill_n(st, n << 1, 0);
	fill_n(lz, n, UINT64_MAX);
	fill_n(in, n, 0);

	while (m--) {
		cin >> t >> l >> r;
		switch (t) {
			case 1:
				{
					cin >> v;
					app(l), app(r - 1);
					l0 = l, r0 = r, l += n, r += n;
					if (l & 1) st[l++] = v;
					if (r & 1) st[--r] = v;
					while (
							v <<= 1,
							(l >>= 1) < (r >>= 1)
							) {
						if (l & 1) lz[l] = v, in[l] = 0, st[l++] = v;
						if (r & 1) lz[--r] = v, in[r] = 0, st[r] = v;
					}
					upd(l0), upd(r0 - 1);
				}
				break;
			case 2:
				{
					cin >> v;
					app(l), app(r - 1);
					l0 = l, r0 = r, l += n, r += n;
					if (l & 1) st[l++] += v;
					if (r & 1) st[--r] += v;
					while (
							v <<= 1,
							(l >>= 1) < (r >>= 1)
							) {
						if (l & 1) st[l] += v, in[l++] += v;
						if (r & 1) st[--r] += v, in[r] += v;
					}
					upd(l0), upd(r0 - 1);
				}
				break;
			default:
				{
					app(l), app(r - 1);
					upd(l), upd(r - 1);
					l += n, r += n;
					res = 0;
					do {
						if (l & 1) res += st[l++];
						if (r & 1) res += st[--r];
					} while ((l >>= 1) < (r >>= 1));
					cout << res << '\n';
				}
		}
	}
}
