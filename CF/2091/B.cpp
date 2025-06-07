#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int64_t TC = 1, n, x, t, ans, a[N];
	cin >> TC;
	while (TC--) {
		ans = t = 0;
		cin >> n >> x;
		for (int i = 0; i < n; ++i) cin >> a[i];
		sort(a, a + n);
		while (n) {
			++t;
			if (t * a[n - 1] >= x) ++ans, t = 0;// cout << n - 1 << ' ';
			--n;
		}
		cout << ans << '\n';
	}
}
