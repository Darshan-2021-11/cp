#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n, k, t, s, e;
	cin >> TC;
	while (TC--) {
		cin >> n >> k;
		s = 1, e = n, t = k - 1;
		for (int i = 0; i < n; ++i) {
			if (t--) cout << e-- << ' ';
			else cout << s++ << ' ', t = k - 1;
		}
		cout << '\n';
	}
}
