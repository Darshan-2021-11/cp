#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n, nc, x, orv;
	cin >> TC;
	while (TC--) {
		orv = 0;
		cin >> n >> x;
		if (n == 1) {
			cout << x << '\n';
			continue;
		}
		nc = n;
		for (int i = 0; i < n - 1; ++i) {
			if ((x | i) != x) break;
			orv |= i;
			cout << i << ' ';
			--nc;
		}
		if (nc == 1 && (((n - 1) | orv) == x)) cout << n - 1 << ' ';
		else for (int i = 0; i < nc; ++i) cout << x << ' ';
		cout << '\n';
	}
}
