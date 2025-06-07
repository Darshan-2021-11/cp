#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, x, y, t;
	cin >> TC;
	while (TC--) {
		cin >> x >> y;
		t = (x + 1 - y);
		cout << (t < 0 || t % 9 ? "NO\n" : "YES\n");
	}
}
