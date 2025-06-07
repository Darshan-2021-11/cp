#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	uint32_t TC = 1, l, r, t, x, a, b;
	cin >> TC;
	while (TC--) {
		x = 0;
		cin >> l >> r;
		for (t = 1 << 29; t; t >>= 1) {
			if ((l & t) == 0 && (r & t) == 0) continue;
			else if ((l & t) != (r & t)) break;
			x |= t;
		}
		a = x | t;
		b = x | (t - 1);
		cout << a << ' ' << b << ' ' << (a == r ? r - 2 : r) << '\n';
	}
}
