#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 5001;
	int TC = 1, pf[N * 12], spf[N] = { 0, 1 }, a[N], pfe[N], f[2][12], fn[2], g, c;
	for (int i = 2; i < N; ++i) {
		if (spf[i]) continue;
		for (int j = i * i; j < N; ++j) spf[j] = i;
	}
	cin >> TC;
	while (TC--) {
		g = c = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i], g = __gcd(g, a[i]);
		for (int i = 0; i < n; ++i) c = a[i] == g, a[i] /= g;
		if (c) {
			cout << n - g << '\n';
			continue;
		}
		pfe[0] = c = 0;
		for (int i = 0, t; i < n; ++i, pfe[i] = c) {
			t = a[i];
			while (t != 1) t /= (pf[c++] = spf[t]);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == j) continue;

			}
		}
	}
}
