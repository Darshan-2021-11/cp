#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 100'001, M = 200'001;
	int TC = 1, n, m, adj[M << 1], nxt[M << 1], head[N], a[N], q[N];
	bool yes;
	//cin >> TC;
	while (TC--) {
		yes = true;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) a[i] = head[i] = 0;
		for (int i = 0, t = 1, u, v; i < m; ++i) {
			cin >> u >> v;
			adj[t] = v, nxt[t] = head[u], head[u] = t++;
			adj[t] = u, nxt[t] = head[v], head[v] = t++;
		}
		for (int i = 1, anc, t, team, front, back; i <= n; ++i) {
			if (a[i]) continue;
			a[i] = 1, front = 0, back = 0, team = 2, q[back++] = i, t = back;
			while (front < back) {
				anc = q[front++];
				for (int j = head[anc], c; j; j = nxt[j]) {
					c = adj[j];
					if (!a[c]) a[c] = team, q[back++] = adj[j];
					if (a[c] == team) continue;
					yes = false; goto next;
				}
				if (front == t) team ^= 3, t = back;
			}
		}
next:
		if (!yes) {
			cout << "IMPOSSIBLE";
			continue;
		}
		for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i == n];
	}
}
