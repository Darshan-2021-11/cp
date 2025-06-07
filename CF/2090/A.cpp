#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, x, y, a;
	cin >> TC;
	while (TC--) {
		cin >> x >> y >> a;
		a %= (x + y);
		if (a < x) cout << "NO\n";
		else cout << "YES\n";
	}
}
