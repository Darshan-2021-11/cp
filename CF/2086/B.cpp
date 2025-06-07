#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'001;
	int64_t TC = 1, n, a[N], k, x, sum, t;
	cin >> TC;
	while (TC--) {
		sum = 0;
		cin >> n >> k >> x;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			sum += a[i];
		}
		if (x > sum * k) {
			cout << 0 << '\n';
			continue;
		}
		t = x / sum;
		if (t * sum == x) {
			k -= t;
			cout << 1 + k * n << '\n';
			continue;
		}
		x -= t * sum, k -= t;
		sum = 0;
		for (int i = n - 1; ~i; --i) {
			sum += a[i];
			if (sum >= x) { t = n - i - 1; break; }
		}
		cout << k * n - t << '\n';
	}
}
