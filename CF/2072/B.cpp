#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, a[2], n;
	int64_t ans;
	char c;
	cin >> TC;
	while (TC--) {
		ans = 1;
		cin >> n;
		a[0] = a[1] = 0;
		for (int i = 0; i < n; ++i) {
			cin >> c;
			a[0] += c == '-';
			a[1] += c == '_';
		}
		if (a[0] < 2) {
			cout << 0 << '\n';
			continue;
		}
		ans *= a[1];
		ans *= a[0] >> 1;
		ans *= (a[0] + 1) >> 1;
		cout << ans << '\n';
	}
}
