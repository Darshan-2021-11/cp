#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000, M = 500'001;
	int TC = 1, n, m, ans, cur, imp, adj[M << 1], nxt[M << 1], head[N];
	char a[M], im[N], ts[10];
	const auto dfs = [&](auto self, int c, int p, bool state) -> void {
		if (im[c] != -1) {
			if (im[c] != state && cur) ans = -1;
			return;
		}
		++cur;
		imp += (im[c] = state);
		for (int i = head[c], u; i != -1; i = nxt[i]) if ((u = adj[i]) != p) {
			self(self, u, c, a[i >> 1] ^ state);
		}
	};
	cin >> TC;
	while (TC--) {
		ans = 0;
		cin >> n >> m;
		for (int i = 0; i < n; ++i) head[i] = im[i] = -1;
		for (int i = 0, u, v, t = 0; i < m; ++i) {
			cin >> u >> v >> ts;
			--u, --v;
			a[t >> 1] = ts[0] == 'i';
			adj[t] = v, nxt[t] = head[u], head[u] = t++;
			adj[t] = u, nxt[t] = head[v], head[v] = t++;
		}
		for (int i = 0; i < n; ++i) {
			cur = imp = 0;
			dfs(dfs, i, i, 1);
			if (ans == -1) goto print;
			ans += max(cur - imp, imp);
		}
print:
		cout << ans << '\n';
	}
}
