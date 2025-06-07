#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int64_t l, r, x, sum, mnsum;
	int TC = 1, a[N], b[N], n, na, nb, tna, tnb;
	bool p;
	cin >> TC;
	while (TC--) {
		cin >> n;
		na = nb = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[na];
			if (a[na] > 0) ++na;
			else b[nb++] = a[na];
		}
		l = 0, r = 2e14 + 1;
		while (l < r) {
			x = l + r >> 1;
			p = true;
			sum = tna = tnb = 0;
			mnsum = LLONG_MIN;
			while (tna + tnb != n) {
				if (tna < na && sum + a[tna] <= x) {
					sum += a[tna++];
					mnsum = max(mnsum, sum);
				} else if (tnb < nb) {
					sum += b[tnb++];
					if (sum < 0) sum = 0;
				} else {
					p = false;
					break;
				}
			}
			if (!p) {
				l = x + 1;
			} else {
				r = x;
			}
		}
		cout << r << '\n';
	}
}
