#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n;
	cin >> TC;
	while (TC--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			for (int j = (i & 1 ? 1 : n); (i & 1 ? j <= n : j > 0); (i & 1 ? ++j : --j))
				cout << j << ' ';
			cout << '\n';
		}
	}
}
