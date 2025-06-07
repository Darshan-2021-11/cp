#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 1'000;
	int TC = 1, n, x, s, mx, a[N], p[N];
	cin >> TC;
	while (TC--) {
		cin >> n >> x;
		cin >> a[0];
		if (n == 1) {
			cout << 1 << '\n';
			continue;
		}
		p[0] = mx = 1;
		for (int i = 1; i < n; ++i) {
			cin >> a[i];
			p[i] = (a[i] < a[i - 1] ? 0 : p[i - 1]) + 1;
			mx = max(mx, p[i]);
		}
		s = 1;
		mx = max(mx, p[n - 2] + (a[n - 1] * x >= a[n - 2]));
		for (int i = n - 2; i; --i) {
			if (a[i] * x >= a[i - 1]) {
				if (a[i] * x <= a[i + 1]) mx = max(mx, s + p[i - 1] + 1);
				else mx = max(mx, p[i - 1] + 1);
			} else {
				if (a[i] * x <= a[i + 1]) mx = max(mx, s + 1);
			}
			s = (a[i] > a[i + 1] ? 0 : s) + 1;
		}
		cout << mx << '\n';
	}
}
