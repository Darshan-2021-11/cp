#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 100'000;
	int64_t d[N << 1], st[N << 1], wtd[N << 1], res;
	int wts[N << 1], lz[N], n, m, h, t, l, r, l0, r0, x;
	const auto app = [&d, &st, &wts, &wtd, &lz, &h, &n] (int idx) -> void {
		idx += n;
		int a = h, u;
		do {
			if (lz[u = idx >> a]) {
				if ((u << 1) < n) lz[u << 1] += lz[u];
				if ((u << 1 | 1) < n) lz[u << 1 | 1] += lz[u];
				st[u << 1] += lz[u] * wts[u << 1], st[u << 1 | 1] += lz[u] * wts[u << 1 | 1];
				d[u << 1] += static_cast<int64_t>(lz[u]) * wtd[u << 1], d[u << 1 | 1] += static_cast<int64_t>(lz[u]) * wtd[u << 1 | 1];
				lz[u] = 0;
			}
		} while (--a);
	};
	const auto upd = [&d, &st, &lz, &n] (int idx) -> void {
		idx += n;
		while (idx >>= 1) {
			if (!lz[idx]) st[idx] = st[idx << 1] + st[idx << 1 | 1], d[idx] = d[idx << 1] + d[idx << 1 | 1];
		}
	};
	cin >> n >> m;
	h = 32 - __builtin_clz(n);
	for (int i = 0; i < n; ++i)
		wtd[i + n] = i + 1, wts[i + n] = 1;
	for (int i = n - 1; i; --i)
		wts[i] = wts[i << 1] + wts[i << 1 | 1], wtd[i] = wtd[i << 1] + wtd[i << 1 | 1];

	for (int i = n; i < n << 1; ++i) cin >> st[i];
	for (int i = n; i < n << 1; ++i) d[i] = static_cast<int64_t>(st[i]) * wtd[i];
	for (int i = n - 1; i; --i)
		st[i] = st[i << 1] + st[i << 1 | 1], 
		d[i] = d[i << 1] + d[i << 1 | 1];
	fill_n(lz, n, 0);
	while (m--) {
		cin >> t >> l >> r;
		--l;
		app(l), app(r - 1);
		l0 = l, r0 = r;
		l += n, r += n;
		if (t == 1) {
			cin >> x;
			if (l & 1) st[l] += x, d[l] += x * wtd[l], ++l;
			if (r & 1) --r, st[r] += x, d[r] += x * wtd[r];
			while ((l >>= 1) < (r >>= 1)) {
				if (l & 1) st[l] += x * wts[l], d[l] += x * wtd[l], lz[l] += x, ++l;
				if (r & 1) --r, st[r] += x * wts[r], lz[r] += x, d[r] += x * wtd[r];
			}
			upd(l0), upd(r0 - 1);
		} else {
			res = 0;
			do {
				if (l & 1) res += d[l++];
				if (r & 1) res += d[--r];
			} while ((l >>= 1) < (r >>= 1));
			l = l0 + n, r = r0 + n;
			do {
				if (l & 1) res -= st[l++] * l0;
				if (r & 1) res -= st[--r] * l0;
			} while ((l >>= 1) < (r >>= 1));
			cout << res << '\n';
		}
	}
}
