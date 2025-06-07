#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 10;
	int TC = 1, n, cnt[3][2], c[2], ans;
	char a[3][N];
	cin >> TC;
	while (TC--) {
		ans = INT_MAX;
		cin >> n;
		c[0] = c[1] = 0;
		for (int i = 0; i < 3; ++i) cnt[i][0] = cnt[i][1] = 0;
		for (int i = 0; i < 3; ++i) for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
			++cnt[i][a[i][j] == '1'];
		}
		for (int i = 0; i < 3; ++i) c[0] += cnt[i][0], c[1] += cnt[i][1];
		if (c[0] % n) {
			cout << -1 << '\n';
			continue;
		}
		for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
			if (i == j) continue;
			ans = min(ans, min(cnt[i][0], cnt[i][1]) + min(cnt[j][0], cnt[j][1]));
		}
		cout << ans << '\n';
	}
}
