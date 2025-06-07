#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, l, r, x;
	cin >> TC;
	while (TC--) {
		x = 0;
		cin >> l >> r;
		for (int i = 1 << 30; i; i >>= 1) {
			if ((r & i) == (l & i)) x |= r & i;
			else { x |= i; break; }
		}
		cout << x << ' ' << x - 1 << ' ' << (x + 1 <= r ? x + 1 : x - 2) << '\n';
	}
}
