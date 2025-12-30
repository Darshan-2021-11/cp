#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	const int N = 10'000;
	int TC = 1, a[N], n, k, cnt;
	double l, r, x;
	//cin >> TC;
	while (TC--) {
		cin >> n >> k;
		for (int i = 0; i < n; ++i) cin >> a[i];
		l = 0, r = 1e7;
		for (int j = 0; j < 60; ++j) {
			cnt = 0;
			x = (l + r) / 2;
			for (int i = 0; i < n; ++i) cnt += a[i] / x;
			if (cnt < k) r = x;
			else l = x;
		}
		cout << setprecision(7) << l << '\n';
	}
}
