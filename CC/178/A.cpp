#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, x, y;
	cin >> TC;
	while (TC--) {
		cin >> x >> y;
		cout << (x == y ? x * 2 : max(x, y) * 2 - 1) << '\n';
	}
}
