#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const uint32_t N = 2'000'000;
	uint32_t mn[N << 1], mx[N << 1], n, k, p, l, r, h, v;
	const auto app = [&st, &mn, &mx, &h, &n](uint32_t idx) -> void {
		idx += n;
		uint32_t t = h, u;
		do {
			u = idx >> t;
			if (st[u] == UINT32_MAX) {
				// left child
				if (mx[u] < mn[u << 1])
					st[u << 1] = mx[u], mn[u << 1] = 0, mx[u << 1] = UINT32_MAX;
				else if (mn[u] > mx[u << 1])
					st[u << 1] = mn[u], mn[u << 1] = 0, mx[u << 1] = UINT32_MAX;
				else {
					mn[u << 1] = max(mn[u << 1], mn[u]), mx[u << 1] = min(mx[u << 1], mx[u]);
					if (st[u << 1] != UINT32_MAX)
						st[u << 1] = max(st[u << 1], mn[u << 1]), st[u << 1] = min(st[u << 1], mx[u << 1]);
				}
				//right child
				if (mx[u] < mn[u << 1 | 1])
					st[u << 1 | 1] = mx[u], mn[u << 1 | 1] = 0, mx[u << 1 | 1] = UINT32_MAX;
				else if (mn[u] > mx[u << 1 | 1])
					st[u << 1 | 1] = mn[u], mn[u << 1 | 1] = 0, mx[u << 1 | 1] = UINT32_MAX;
				else {
					mn[u << 1 | 1] = max(mn[u << 1 | 1], mn[u]), mx[u << 1 | 1] = min(mx[u << 1 | 1], mx[u]);
					if (st[u << 1 | 1] != UINT32_MAX)
						st[u << 1 | 1] = max(st[u << 1 | 1], mn[u << 1 | 1]), st[u << 1 | 1] = min(st[u << 1 | 1], mx[u << 1 | 1]);
				}
			} else {
				st[u << 1] = st[u << 1 | 1] = st[u],
				mn[u << 1] = mn[u << 1 | 1] = mn[u],
				mx[u << 1] = mx[u << 1 | 1] = mx[u],
				st[u] = UINT32_MAX;
			}
			mn[u] = 0, mx[u] = UINT32_MAX;
		} while (--t);
	};
	cin >> n >> k;
	h = 32 - __builtin_clz(n);
	fill_n(st, n, UINT32_MAX);
	fill_n(st + n, n << 1, 0);
	fill_n(mn, n << 1, 0);
	fill_n(mx, n << 1, UINT32_MAX);

	while (k--) {
		cin >> p >> l >> r >> v;
		++r;
		app(l), app(r - 1);
		l += n, r += n;
		if (p == 1) {
			do {
				if (l & 1) {
					if (v >= mx[l]) st[l] = v, mn[l] = 0, mx[l] = UINT32_MAX;
					else mn[l] = max(mn[l], v);
					++l;
				}
				if (r & 1) {
					--r;
					if (v >= mx[r]) st[r] = v, mn[r] = 0, mx[r] = UINT32_MAX;
					else mn[r] = max(mn[r], v);
				}
			} while ((l >>= 1) < (r >>= 1));
		} else {
			do {
				if (l & 1) {
					if (mn[l] >= v) st[l] = v, mn[l] = 0, mx[l] = UINT32_MAX;
					else mx[l] = min(mx[l], v);
					++l;
				}
				if (r & 1) {
					--r;
					if (mn[r] >= v) st[r] = v, mn[r] = 0, mx[r] = UINT32_MAX;
					else mx[r] = min(mx[r], v);
				}
			} while ((l >>= 1) < (r >>= 1));
		}
		/*
			 cout << '\n';
			 cout << "st:\n";
			 for (uint32_t i = 1; i < n << 1; ++i) {
			 cout << st[i] << ' ';
			 if (!(i & (i + 1))) cout << '\n';
			 }
			 cout << '\n';
			 cout << "mn:\n";
			 for (uint32_t i = 1; i < n << 1; ++i) {
			 cout << mn[i] << ' ';
			 if (!(i & (i + 1))) cout << '\n';
			 }
			 cout << '\n';
			 cout << "mx:\n";
			 for (uint32_t i = 1; i < n << 1; ++i) {
			 cout << mx[i] << ' ';
			 if (!(i & (i + 1))) cout << '\n';
			 }
			 cout << '\n';
		*/
	}
	for (uint32_t i = 0; i < n; ++i) {
		if (st[i] == UINT32_MAX) {
			// left child
			if (mx[i] < mn[i << 1])
				st[i << 1] = mx[i], mn[i << 1] = 0, mx[i << 1] = UINT32_MAX;
			else if (mn[i] > mx[i << 1])
				st[i << 1] = mn[i], mn[i << 1] = 0, mx[i << 1] = UINT32_MAX;
			else {
				mn[i << 1] = max(mn[i << 1], mn[i]), mx[i << 1] = min(mx[i << 1], mx[i]);
				if (st[i << 1] != UINT32_MAX)
					st[i << 1] = max(st[i << 1], mn[i << 1]), st[i << 1] = min(st[i << 1], mx[i << 1]);
			}
			//right child
			if (mx[i] < mn[i << 1 | 1])
				st[i << 1 | 1] = mx[i], mn[i << 1 | 1] = 0, mx[i << 1 | 1] = UINT32_MAX;
			else if (mn[i] > mx[i << 1 | 1])
				st[i << 1 | 1] = mn[i], mn[i << 1 | 1] = 0, mx[i << 1 | 1] = UINT32_MAX;
			else {
				mn[i << 1 | 1] = max(mn[i << 1 | 1], mn[i]), mx[i << 1 | 1] = min(mx[i << 1 | 1], mx[i]);
				if (st[i << 1 | 1] != UINT32_MAX)
					st[i << 1 | 1] = max(st[i << 1 | 1], mn[i << 1 | 1]), st[i << 1 | 1] = min(st[i << 1 | 1], mx[i << 1 | 1]);
			}
		} else {
			st[i << 1] = st[i << 1 | 1] = st[i],
			mn[i << 1] = mn[i << 1 | 1] = mn[i],
			mx[i << 1] = mx[i << 1 | 1] = mx[i];
		}
	}
	for (uint32_t i = n; i < n << 1; ++i) {
		st[i] = max(st[i], mn[i]), st[i] = min(st[i], mx[i]);
		cout << st[i] << '\n';
	}
}
