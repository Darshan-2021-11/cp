#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n, m, l, r, x, y;
	cin >> TC;
	while (TC--) {
		x= y = 0;
		cin >> n >> m >> l >> r;
		for (int i = 0; i < m; ++i) {
			if (x - 1 >= l) --x;
			else if (y + 1 <= r) ++y;
		}
		cout << x << ' ' << y << '\n';
	}
}
