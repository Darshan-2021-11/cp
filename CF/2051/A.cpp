#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 101;
	int TC = 1, n, a[N], b[N], ans;
	cin >> TC;
	while (TC--) {
		ans = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> b[i];
		b[n] = 0;
		for (int i = 0; i < n; ++i) {
			a[i] -= b[i + 1];
			if (a[i] > 0) ans += a[i];
		}
		cout << ans << '\n';
	}
}
