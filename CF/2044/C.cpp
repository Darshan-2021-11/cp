#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, m, a, b, c, r1, r2;
	cin >> TC;
	while (TC--) {
		cin >> m >> a >> b >> c;
		r1 = max(m - a, 0);
		r2 = max(m - b, 0);
		cout << min(m, a) + min(m, b) + min(c, r1 + r2) << '\n';
	}
}
