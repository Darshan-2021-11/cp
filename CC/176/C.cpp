#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int64_t TC = 1, n, m, x, b[100], bn;
	cin >> TC;
	while (TC--) {
		cin >> n >> m;
		x = n, bn = 0;
		for (int i = 62; ~i; --i) {
			if ((x & (1LL << i)) || (x | (1LL << i)) > m) continue;
			b[bn++] = (1LL << i) | x;
		}
		if (x < m) b[bn++] = x;
		if (bn <= 1) {
			cout << -1 << '\n';
			continue;
		}
		cout << bn << '\n';
		for (int i = 0; i < bn; ++i)
			cout << b[i] << ' ';
		cout << '\n';
	}
}
