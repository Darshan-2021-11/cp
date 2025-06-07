#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 100'001, M = 200'001;
	int TC = 1, n, m, adj[M << 1], nxt[N << 1], head[N], p[N], t, q[N], qn;
	bool yes;
	const auto dfs = [&adj, &nxt, &head, &p, &q, &t, &qn, &yes] (int c, int a, auto &&self) -> bool {
		if (p[c]) return false;
		p[c] = a;
		for (int i = head[c], u; i; i = nxt[i]) if ((u = adj[i]) != a) {
			if (self(u, c, self)) {
			}
		}
		return false;
	};
	//cin >> TC;
	while (TC--) {
		t = qn = yes = false;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) head[i] = p[i] = 0;
		for (int i = 0, sz = 1, u, v; i < m; ++i) {
			cin >> u >> v;
			adj[sz] = v, nxt[sz] = head[u], head[u] = sz++;
			adj[sz] = u, nxt[sz] = head[v], head[v] = sz++;
		}
		for (int i = 1; i <= n; ++i) {
			if (p[i]) continue;
			dfs(i, i, dfs);
			if (yes) break;
		}
		if (!yes) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		cout << qn << '\n';
		for (int i = 0; i < qn; ++i) cout << q[i] << " \n"[i == qn - 1];
	}
}
