#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, a[3], b[4], ans;
	cin >> TC;
	while (TC--) {
		ans = 0;
		for (int i = 0; i < 3; ++i) cin >> a[i];
		reverse(a, a + 3);
		for (int i = 0, t; i < 3; ++i) {
			cin >> b[i];
		}
		reverse(b, b + 3);
		for (int i = 0, t; i < 3; ++i) {
			t = min(a[i], b[i]);
			ans += t;
			a[i + 1] += a[i] - t;
		}
		cout << ans << '\n';
	}
}
