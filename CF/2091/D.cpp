#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n, m, k, l, r, x;
	cin >> TC;
	while (TC--) {
		cin >> n >> m >> k;
		k = (k + n - 1) / n;
		l = 1, r = m + 1;
		while (l < r) {
			x = l + r >> 1;
			if (k + ((k - 1) / x) <= m) r = x;
			else l = x + 1;
		}
		cout << r << '\n';
	}
}
