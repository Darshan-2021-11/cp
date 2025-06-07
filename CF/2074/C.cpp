#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, x, t;
	cin >> TC;
	while (TC--) {
		cin >> x;
		if (x < 5 || (x & (x - 1)) == 0 || (x & (x + 1)) == 0) cout << -1 << '\n';
		else {
			for (t = 1 << 30; t; t >>= 1) {
				if (x & t) break;
			}
			cout << t - 1 << '\n';
		}
	}
}
