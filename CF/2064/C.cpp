#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int64_t pf[N], mx, sum;
	int TC = 1, n, a[N];
	cin >> TC;
	while (TC--) {
		mx = LLONG_MIN;
		cin >> n >> a[0];
		pf[0] = max(a[0], 0);
		for (int i = 1; i < n; ++i) {
			cin >> a[i];
			pf[i] = pf[i - 1] + max(a[i], 0);
		}
		sum = 0;
		for (int i = n - 1; ~i; --i) {
			sum -= min(a[i], 0);
			mx = max(mx, pf[i] + sum);
		}
		cout << mx << '\n';
	}
}
