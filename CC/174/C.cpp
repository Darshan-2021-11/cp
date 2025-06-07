#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 400'000;
	int64_t TC = 1, n, cn, a[N], ans, g, p, cnt, idx;
	int f[N];
	cin >> TC;
	while (TC--) {
		g = 0;
		cin >> n;
		cn = n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			g = gcd(a[i], g);
		}
		ans = g + n;
		sort(a, a + n);
		p = idx = -1;
		for (int i = 0; i < n; ++i) {
			if (a[i] != p) ++idx, a[idx] = p = a[i], f[idx] = 1;
			else ++f[idx];
		}
		n = ++idx;
		ans = max(ans, a[n - 1] + f[n - 1]);
		for (int64_t i = max(a[n - 1] - cn, static_cast<int64_t>(1)); i < a[n - 1]; ++i) {
			cnt = 0;
			for (int64_t j = i; j <= a[n - 1]; j += i) {
				idx = lower_bound(a, a + n, j) - a;
				if (a[idx] != j) continue;
				cnt += f[idx];
			}
			if (cnt) ans = max(ans, cnt + i);
		}
		cout << ans << '\n';
	}
}
