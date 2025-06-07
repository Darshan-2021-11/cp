#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, n, x, a[N], b[N], cmpl, mx, mn;
	bool pos;
	cin >> TC;
	while (TC--) {
		pos = true, cmpl = mx = INT_MIN, mn = INT_MAX;
		cin >> n >> x;
		for (int i = 0; i < n; ++i) cin >> a[i], mx = max(mx, a[i]), mn = min(mn, a[i]);
		for (int i = 0; i < n; ++i) {
			cin >> b[i];
			if (b[i] != -1) cmpl = a[i] + b[i];
		}
		if (cmpl == INT_MIN) {
			cmpl = mx;
			for (int i = 0; i < n; ++i) {
				pos &= (((cmpl - a[i]) <= x) && ((cmpl - a[i]) >= 0));
			}
			cout << (pos ? max(0, x + mn - mx + 1) : 0) << '\n';
		} else {
			for (int i = 0; i < n; ++i) {
				if (b[i] == -1) pos &= (((cmpl - a[i]) <= x) && ((cmpl - a[i]) >= 0));
				else pos &= ((a[i] + b[i]) == cmpl);
			}
			cout << pos << '\n';
		}
	}
}
