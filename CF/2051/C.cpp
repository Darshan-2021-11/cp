#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 300'000;
	int TC = 1, n, m, k, a[N];
	bitset<N> know;
	cin >> TC;
	while (TC--) {
		cin >> n >> m >> k;
		for (int i = 0; i < n; ++i) know[i] = false;
		for (int i = 0; i < m; ++i) cin >> a[i];
		for (int i = 0, t; i < k; ++i) cin >> t, know[t - 1] = true;
		if (k < n - 1) for (int i = 0; i < m; ++i) cout << 0;
		else if (k == n - 1) for (int i = 0; i < m; ++i) cout << !know[a[i] - 1];
		else for (int i = 0; i < m; ++i) cout << 1;
		cout << '\n';
	}
}
