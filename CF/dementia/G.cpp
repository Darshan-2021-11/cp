#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, n, mx, ans, adj[N << 1], nxt[N << 1], sz[N], depth[N], head[N];
	bool dt[N], taken[N];
	cin >> TC;

	const auto dfs1 = [&](auto self, int c, int p) -> void {
		depth[c] = depth[p] + 1;
		mx = max(depth[c], mx);
		for (int i = head[c], u; i != -1; i = nxt[i]) if ((u = adj[i]) != p) {
			self(self, u, c);
		}
	};
	const auto dfs2 = [&](auto self, int c, int p) -> bool {
		if (depth[c] == mx) {
			if (!dt[depth[c]]) {
				dt[depth[c]] = true;
				taken[c] = true;
				return true;
			}
			return false;
		}
		for (int i = head[c], u; i != -1; i = nxt[i]) if ((u = adj[i]) != p) {
			bool t = self(self, u, c);
			if (t && !dt[depth[c]]) {
				dt[depth[c]] = true;
				taken[c] = true;
				return true;
			}
		}
		return false;
	};
	const auto dfs3 = [&](auto self, int c, int p, int d) -> void {
		if (sz[c] == 1 && c != 0) {
			ans = max(ans, d - taken[c]);
			return;
		}
		for (int i = head[c], u; i != -1; i = nxt[i]) if ((u = adj[i]) != p) {
			if (taken[c])
				self(self, u, c, 1);
			else
				self(self, u, c, d + 1);
		}
	};

	while (TC--) {
		mx = INT_MIN, ans = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) head[i] = -1, sz[i] = dt[i] = taken[i] = false;
		for (int i = 1, t = 0, u, v; i < n; ++i) {
			cin >> u >> v;
			--u, --v;
			adj[t] = v, nxt[t] = head[u], head[u] = t++, ++sz[u];
			adj[t] = u, nxt[t] = head[v], head[v] = t++, ++sz[v];
		}
		depth[0] = 0;
		for (int i = head[0]; i != -1; i = nxt[i]) {
			dfs1(dfs1, adj[i], 0);
		}
		dfs2(dfs2, 0, 0);
		dfs3(dfs3, 0, 0, 1);
		cout << mx + ans << '\n';
	}
}
