#include <bits/stdc++.h>
using namespace std;

const int N = 100'001;
int TC = 1, n, m, anc[N], rnk[N], res[N], rn;

static int find(int u) {
	if (anc[u] == u) return u;
	return anc[u] = find(anc[u]);
};
static void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return;
	if (rnk[u] == rnk[v]) anc[v] = u, ++rnk[u];
	else {
		if (rnk[u] < rnk[v]) swap(u, v);
		anc[v] = u;
	}
};

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	while (TC--) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) anc[i] = i, rnk[i] = 0;
		for (int i = 0, u, v; i < m; ++i) {
			cin >> u >> v;
			merge(u, v);
		}
		rn = -1;
		for (int i = 1; i <= n; ++i) if (anc[i] == i) res[++rn] = i;
		cout << rn << '\n';
		for (int i = 0; i < rn; ++i) {
			cout << res[i] << ' ' << res[i + 1] << '\n';
		}
	}
}
