#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n, m, k, kc;
	cin >> TC;
	while (TC--) {
		cin >> n >> m >> k;
		kc = k;
		if (k < abs(n - m) || k > max(n, m)) {
			cout << -1 << '\n';
			continue;
		}
		char last = -1;
		while (k--) cout << (last = (n > m ? '0' : '1'));
		if (n > m) {
			n -= kc;
			while (m > n) cout << (last = '1'), --m;
		} else {
			m -= kc;
			while (n > m) cout << (last = '0'), --n;
		}
		assert(n == m);
		while (m--) cout << (last == '1' ? "01" : "10");
		cout << '\n';
	}
}
