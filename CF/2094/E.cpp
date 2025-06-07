#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int64_t TC = 1, a[N], b[30], n, mx, t;
	cin >> TC;
	while (TC--) {
		mx = 0;
		cin >> n;
		fill_n(b, 30, 0);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			for (int j = 0; j < 30; ++j) b[j] += (a[i] & (1 << j)) > 0;
		}
		for (int i = 0; i < n; ++i) {
			t = 0;
			for (int j = 0; j < 30; ++j) {
				if (a[i] & (1 << j)) {
					t += int64_t(1 << j) * (n - b[j]);
				} else {
					t += int64_t(1 << j) * (b[j]);
				}
			}
			mx = max(t, mx);
		}
		cout << mx << '\n';
	}
}
