#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, x, y;
	cin >> TC;
	while (TC--) {
		cin >> x >> y;
		x >>= 1;
		for (int i = 0; i < x; ++i) cout << 1;
		for (int i = 0; i < y; ++i) cout << 2;
		for (int i = 0; i < x; ++i) cout << 1;
		cout << '\n';
	}
}
