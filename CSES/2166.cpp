#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int64_t TC = 1, n, q, t, st[N << 1], mx[N], res;
	//cin >> TC;
	while (TC--) {
		cin >> n >> q;
		for (int i = n; i < n << 1; ++i) cin >> st[i];
		for (int i = n - 1; i >= n >> 1; --i) st[i] = st[i << 1] + st[i << 1 | 1], mx[i] = max(st[i << 1], st[i]);
		for (int i = (n >> 1) - 1; i > 0; --i) st[i] = st[i << 1] + st[i << 1 | 1], mx[i] = max(mx[i << 1], st[i << 1] + mx[i << 1 | 1]);
		while (q--) {
			cin >> t;
			if (t == 1) {
				int k, u;
				cin >> k >> u;
				k += n - 1;
				st[k] = u;
				k >>= 1;
				st[k] = st[k << 1] + st[k << 1 | 1], mx[k] = max(st[k << 1], st[k]);
				while (k >>= 1) st[k] = st[k << 1] + st[k << 1 | 1], mx[k] = max(mx[k << 1], st[k << 1] + mx[k << 1 | 1]);
			} else {
				int a, b, stk[32], stkn = 0;
				cin >> a >> b;
				a += n - 1, b += n, res = 0, t = 0;
				if (a & 1) res = max(res, st[a]), t += st[a], ++a;
				if (b & 1) stk[stkn++] = --b;
				while ((a >>= 1) < (b >>= 1)) {
					if (a & 1) res = max(res, t + mx[a]), t += st[a], ++a;
					if (b & 1) stk[stkn++] = --b;
				}
				while (stkn--) {
					if (stk[stkn] < n) res = max(res, t + mx[stk[stkn]]), t += st[stk[stkn]];
					else res = max(res, t + st[stk[stkn]]);
				}
				cout << res << '\n';
			}
		}
	}
}
