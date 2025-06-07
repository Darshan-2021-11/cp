#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, n, a[N], yes;
	cin >> TC;
	while (TC--) {
		yes = true;
		cin >> n;
		for (int i = 0; i < n; ++i) a[i] = 0;
		for (int i = 0, t; i < n; ++i) cin >> t, ++a[t];
		for (int i = 0; i <= n >> 1; ++i) yes &= a[i] + a[n - 1 - i] == 2;
		if (!yes) cout << 0 << '\n';
		else {
			int x = 1;
			for (int i = 0; i < n >> 1; ++i) (x <<= 1) %= 998244353;
			cout << x << '\n';
		}
	}
}
