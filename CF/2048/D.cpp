#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 300'000;
	int64_t ans;
	int TC = 1, n, m, a[N], b[N], c[N], kr, kridxa, kridxb;
	cin >> TC;
	while (TC--) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < m; ++i) cin >> b[i];
		kr = a[0];
		sort(a, a + n);
		sort(b, b + m);
		kridxa = n - 1; while (~kridxa && a[kridxa] > kr) --kridxa;
		kridxb = m - 1; while (~kridxb && b[kridxb] > kr) --kridxb;
		for (int i = kridxb + 1; i < m; ++i) {
			c[i] = n - (lower_bound(a, a + n, b[i]) - a);
		}
		for (int i = 1, j; i <= m; ++i) {
			ans = m / i;
			for (j = kridxb + 1 + m % i; j < m; j += i)
				ans += c[j];
			cout << ans << ' ';
		}
		cout << '\n';
	}
}
