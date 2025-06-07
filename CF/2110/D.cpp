#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int64_t maxr = 1e15;
	const int N = 200'000, M = 300'000;
	int64_t dp[N], l, r, x;
	int TC = 1, n, m, a[N], b[M], nxt[M], adj[M], head[N];
	cin >> TC;
	while (TC--) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i) cin >> a[i], head[i] = -1;
		for (int i = 0, u, v; i < m; ++i) {
			cin >> u >> v >> b[i];
			--u, --v;
			adj[i] = v, nxt[i] = head[u], head[u] = i;
		}
		l = 1, r = maxr;
		while (l < r) {
			x = l + r >> 1;
			fill_n(dp, n, 0);
			dp[0] = min<int64_t>(a[0], x);
			for (int j = 0; j < n; ++j) {
				if (!dp[j]) continue;
				for (int i = head[j]; i != -1; i = nxt[i]) {
					if (b[i] > dp[j]) continue;
					else dp[adj[i]] = min(max(dp[adj[i]], dp[j] + a[adj[i]]), x);
				}
			}
			if (dp[n - 1]) r = x;
			else l = x + 1;
		}
		cout << (l != maxr ? l : -1) << '\n';
	}
}
