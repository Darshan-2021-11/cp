#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n, k, p, x;
	cin >> TC;
	while (TC--) {
		cin >> n >> k >> p;
		if (k < 0) k = -k;
		if ((x = (k + p - 1) / p) > n) {
			cout << -1 << '\n';
		} else {
			cout << x << '\n';
		}
	}
}
