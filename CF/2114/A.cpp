#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n, t;
	cin >> TC;
	while (TC--) {
		cin >> n;
		t = sqrtl(n);
		if (t * t == n) cout << t << ' ' << 0 << '\n';
		else cout << -1 << '\n';
	}
}
