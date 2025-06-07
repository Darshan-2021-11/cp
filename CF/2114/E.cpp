#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int64_t ans[N];
	int TC = 1, n, a[N], adj[N << 1], nxt[N << 1], head[N];
	const auto dfs = [&](auto &&self, int64_t sum0, int64_t sum1, int c, int p, bool v) -> void {
		if (v) {
			sum0 = max(sum0 - a[c], int64_t(0));
			sum1 = max(sum1 + a[c], int64_t(a[c]));
			ans[c] = sum1;
		} else {
			sum0 = max(sum0 + a[c], int64_t(a[c]));
			sum1 = max(sum1 - a[c], int64_t(0));
			ans[c] = sum0;
		}
		for (int i = head[c], u; i != -1; i = nxt[i]) if ((u = adj[i]) != p) {
			self(self, sum0, sum1, u, c, !v);
		}
	};
	cin >> TC;
	while (TC--) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i], head[i] = -1;
		for (int i = 1, t = 0, u, v; i < n; ++i) {
			cin >> u >> v;
			--u, --v;
			adj[t] = v, nxt[t] = head[u], head[u] = t++;
			adj[t] = u, nxt[t] = head[v], head[v] = t++;
		}
		dfs(dfs, 0, 0, 0, 0, 0);
		for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
		cout << '\n';
	}
}
