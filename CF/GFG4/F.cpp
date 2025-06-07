#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	uint64_t l, r, x, v, n;
	int TC = 1;
	cin >> TC;
	while (TC--) {
		l = 0, r = 316'227'766;
		cin >> n;
		--n;
		while (l < r) {
			x = l + r + 1 >> 1;
			v = x * (x + 1) * 13;
			if (v > n) r = x - 1;
			else l = x;
		}
		n -= l * (l + 1) * 13;
		cout << char('a' + n / (l + 1)) << '\n';
	}
}
