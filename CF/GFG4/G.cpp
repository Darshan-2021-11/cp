#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 1'000'001;
	array<int64_t, 2> ka[N];
	int64_t s, mx, a[N];
	int TC = 1, n, kn;
	cin >> TC;
	while (TC--) {
		s = mx = kn = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];

		ka[kn][0] = 0, ka[kn++][1] = -1;
		for (int i = 0; i < n; ++i) {
			s = max({ s + a[i], a[i], int64_t{} });
			mx = max(mx, s);
			ka[kn  ][0] = s;
			ka[kn++][1] = i;
		}
		sort(ka, ka + kn);
		/*
		for (int i = 0; i < kn; ++i) cout << ka[i][0] << ',' << ka[i][1] << ' ';
		cout << '\n';
		*/

		--kn, s = 0;
		for (int i = n - 1; ~i; --i) {
			s += a[i];
			if (s < 0) continue;
			while (ka[kn][1] >= i) --kn;
			mx = max(mx, s + ka[kn][0]);
		}

		s = kn = 0;
		ka[kn][0] = 0, ka[kn++][1] = n;
		for (int i = n - 1; ~i; --i) {
			s = max({ s + a[i], a[i], int64_t{} });
			mx = max(mx, s);
			ka[kn  ][0] = s;
			ka[kn++][1] = i;
		}
		sort(ka, ka + kn);
		/*
		for (int i = 0; i < kn; ++i) cout << ka[i][0] << ',' << ka[i][1] << ' ';
		cout << '\n';
		*/

		--kn, s = 0;
		for (int i = 0; i < n; ++i) {
			s += a[i];
			if (s < 0) continue;
			while (ka[kn][1] <= i) --kn;
			mx = max(mx, s + ka[kn][0]);
		}

		cout << mx << '\n';
	}
}
