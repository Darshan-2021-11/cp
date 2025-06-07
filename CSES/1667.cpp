#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 100'001, M = 200'001;
	int TC = 1, adj[M << 1], nxt[M << 1], h[N], q[N], a[N], p[N], n, m;
	//cin >> TC;
	while (TC--) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) h[i] = a[i] = 0;
		for (int i = 0, t = 1, u, v; i < m; ++i) {
			cin >> u >> v;
			adj[t] = v, nxt[t] = h[u], h[u] = t++;
			adj[t] = u, nxt[t] = h[v], h[v] = t++;
		}
		int back = 0, front = 0;
		q[back++] = a[1] = 1, p[1] = 0;
		while (front < back) {
			int anc = q[front++];
			for (int c, i = h[anc]; i; i = nxt[i]) {
				c = adj[i];
				if (!a[c]) {
					a[c] = a[anc] + 1, p[c] = anc, q[back++] = c;
					if (c == n) goto next;
				}
			}
		}
next:
		if (!a[n]) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		m = n, n = 0;
		do nxt[n++] = m, m = p[m]; while (m);
		cout << n << '\n';
		for (int i = n - 1; ~i; --i) {
			cout << nxt[i] << " \n"[!i];
		}
	}
}
