#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int64_t TC = 1, n, m, l, r, x, t, u, s;
	cin >> TC;
	while (TC--) {
		cin >> n >> m;
		l = 0, r = n - 1;
		while (l < r) {
			x = (l + r + 1) >> 1;
			s = ((((n - 1) << 1) - (x - 1)) * x) >> 1;
			if (s > m) r = x - 1;
			else l = x;
		}
		t = (l * (l + 1)) >> 1;
		r = max(m - (((n - 2) * (n - 1)) >> 1), int64_t{0});
		u = (r * (r - 1)) >> 1;
		cout << t - u << '\n';
	}
}
