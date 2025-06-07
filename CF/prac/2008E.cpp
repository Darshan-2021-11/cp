#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'001;
	int TC = 1, n, nc, ans, mn[2], cnt[2][26], pcnt[2][26];
	char a[N];
	cin >> TC;
	while (TC--) {
		ans = INT_MAX;
		cin >> n >> a;
		nc = n >> 1;
		for (int i = 0; i < 26; ++i) cnt[0][i] = cnt[1][i] = 0;
		for (int i = 0; i < n; ++i) ++cnt[i & 1][a[i] - 'a'];
		if (n & 1) {
			for (int i = 0; i < 26; ++i) pcnt[0][i] = pcnt[1][i] = 0;
			for (int i = 0; i < n; ++i) {
				fill_n(mn, 2, INT_MAX);
				--cnt[i & 1][a[i] - 'a'];
				for (int j = 0; j < 2; ++j)
					for (int k = 0; k < 26; ++k)
						mn[j] = min(mn[j], nc - (cnt[j][k] + pcnt[j ^ 1][k]));
				ans = min(ans, mn[0] + mn[1]);
				++pcnt[i & 1][a[i] - 'a'];
			}
		} else {
			fill_n(mn, 2, INT_MAX);
			for (int j = 0; j < 2; ++j)
				for (int i = 0; i < 26; ++i)
				mn[j] = min(mn[j], nc - cnt[j][i]);
			ans = min(ans, mn[0] + mn[1]);
		}
		cout << ans + (n & 1) << '\n';
	}
}
