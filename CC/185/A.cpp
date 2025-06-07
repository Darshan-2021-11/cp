#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, n, k;
	cin >> TC;
	while (TC--) {
		cin >> n >> k;
		if (k - n + 2 < 1) {
			cout << -1 << '\n';
			continue;
		}
		cout << k - n + 2 << ' ' << (k - n + 2) * 2 << ' ';
		for (int i = 2; i < n; ++i) cout << (k - n + 2) * 2 + i - 1 << ' ';
		cout << '\n';
	}
}
