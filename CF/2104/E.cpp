#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 1'000'010;
	int TC = 1, n, k, q, nxt[N][26], dp[N], tmp[26];
	string a, s;
	a.reserve(N), s.reserve(N);
	while (TC--) {
		cin >> n >> k >> a;
		fill_n(tmp, k, n + 1);
		for (int j = 0; j < k; ++j) nxt[n + 1][j] = tmp[j];
		for (int i = n; i; --i) {
			for (int j = 0; j < k; ++j) nxt[i][j] = tmp[j];
			tmp[a[i - 1] - 'a'] = i;
		}
		for (int j = 0; j < k; ++j) nxt[0][j] = tmp[j];
		dp[n + 1] = 0;
		for (int i = n; i; --i) {
			int mn = INT_MAX;
			for (int j = 0; j < k; ++j) {
				mn = min(mn, dp[nxt[i][j]]);
			}
			dp[i] = mn + 1;
		}
		cin >> q;
		while (q--) {
			cin >> s;
			int idx = 0;
			for (const auto &i: s) {
				idx = nxt[idx][i - 'a'];
			}
			cout << dp[idx] << '\n';
		}
	}
}
