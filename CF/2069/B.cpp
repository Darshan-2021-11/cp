#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 700;
	int TC = 1, a[N * N], n, m, nm, cnt, ans;
	vector<bool> mp(N * N);
	cin >> TC;
	while (TC--) {
		ans = cnt = 0;
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> a[i * m + j];
				--a[i * m + j];
				mp[a[i * m + j]] = false;
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (i < n - 1) mp[a[i * m + j]] = mp[a[i * m + j]] | (a[(i + 1) * m + j] == a[i * m + j]);
				if (j < m - 1) mp[a[i * m + j]] = mp[a[i * m + j]] | (a[i * m + (j + 1)] == a[i * m + j]);
			}
		}
		sort(a, a + n * m);
		nm = unique(a, a + n * m) - a;
		for (int i = 0; i < nm; ++i) {
			ans += 1 + mp[a[i]], cnt += mp[a[i]];
		}
		cout << ans - 1 - (cnt != 0) << '\n';
	}
}
