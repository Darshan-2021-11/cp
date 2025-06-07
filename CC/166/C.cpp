#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 300'000;
	int TC, n, a[N], b[N], t;
	cin >> TC;
	while (TC--) {
		t = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		iota(b, b + n, 0);
		sort(b, b + n, [&](int x, int y) {
				return a[x] > a[y];
				});
		for (int i = 1; i < n; ++i) t += abs(b[i] - b[i - 1]) == 1;
		cout << n - t << '\n';
	}
}

