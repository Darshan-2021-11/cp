#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000, MOD = 1e9 + 7;
	int64_t cnt;
	int TC = 1, n, a[N], st[N << 1];
	//cin >> TC;
	while (TC--) {
		cnt = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
		fill_n(st, n << 1, 0);
		for (int i = 0; i < n; ++i) {
			int l = a[i] + 1 + n, r = n << 1;
			while (l < r) {
				if (l & 1) cnt += st[l], ++l;
				if (r & 1) --r, cnt += st[r];
				l >>= 1, r >>= 1;
			}
			if (cnt >= MOD) cnt -= MOD;
			l = a[i] + n;
			for (++st[l]; l >>= 1;) st[l] = st[l << 1] + st[l << 1 | 1];
		}
		fill_n(st, n << 1, 0);
		for (int i = n - 1; ~i; --i) {
			int l = n, r = a[i] + n;
			while (l < r) {
				if (l & 1) cnt += st[l], ++l;
				if (r & 1) --r, cnt += st[r];
				l >>= 1, r >>= 1;
			}
			if (cnt >= MOD) cnt -= MOD;
			l = a[i] + n;
			for (++st[l]; l >>= 1;) st[l] = st[l << 1] + st[l << 1 | 1];
		}
		cout << cnt << '\n';
	}
}
