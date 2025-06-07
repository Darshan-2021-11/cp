#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n, m, k, res;
	cin >> TC;
	while (TC--) {
		res = INT_MAX;
		cin >> n >> m >> k;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				res = min(res, abs(k - ((i + j) << 1)));
		cout << res << '\n';
	}
}
