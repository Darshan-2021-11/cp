#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, n, a[N], b[N][2];
	bool pos;
	cin >> TC;
	while (TC--) {
		pos = true;
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> b[i][0] >> b[i][1];
		for (int i = n - 1; i; --i) b[i - 1][1] = min(b[i][1] - (a[i] == 1), b[i - 1][1]);
		for (int i = 0, cnt = 0, mn = 0; i < n; ++i) {
			mn = max(b[i][0], mn);
			b[i][0] = mn;
			if (a[i] == -1) a[i] = cnt < b[i][1];
			cnt += a[i];
			pos &= cnt >= b[i][0] && cnt <= b[i][1];
		}
		if (pos) {
			for (int i = 0; i < n; ++i) cout << a[i] << ' ';
		} else cout << -1;
		cout << '\n';
	}
}
