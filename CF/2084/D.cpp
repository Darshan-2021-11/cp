#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, a[N], n, m, k, v;
	cin >> TC;
	while (TC--) {
		cin >> n >> m >> k;
		int rep = min(n - m * k, n / (m + 1));
		rep = max(rep, k);
		for (int i = 0, j = 0; i < n; ++i, ++j) {
			if (j == rep) j = 0;
			a[i] = j;
		}
		for (int i = 0; i < n; ++i) cout << a[i] << ' ';
		cout << '\n';
	}
}
