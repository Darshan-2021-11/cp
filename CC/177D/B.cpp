#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, x, y, k;
	cin >> TC;
	while (TC--) {
		cin >> x >> y >> k;
		cout << ((abs(x - y) & 1) == (k & 1) ? abs(k - abs(x - y)) >> 1 : -1) << '\n';
	}
}
