#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n;
	cin >> TC;
	while (TC--) {
		cin >> n;
		if (n == 1) {
			cout << -1 << '\n';
			continue;
		} else if (n & 1) {
			for (int i = 0; i <= n >> 1; ++i) cout << 1 << ' ';
			for (int i = 0; i < (n >> 1) - 1; ++i) cout << -1 << ' ';
			cout << -2;
		} else {
			for (int i = 0; i < n >> 1; ++i) cout << 1 << ' ' << -1 << ' ';
		}
		cout << '\n';
	}
}
