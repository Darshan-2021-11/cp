#include <bits/stdc++.h>
using namespace std;

template <int N> struct dsu {
	int size[N], anc[N];
	void init(int n) {
		for (int v = 0; v < n; ++v) 
			size[v] = 1, anc[v] = v;
	}
	int find(int v) {
		if (anc[v] == v) return v;
		return anc[v] = find(anc[v]);
	}
	bool merge(int v1, int v2) {
		if ((v1 = find(v1)) == (v2 = find(v2))) return false;
		if (size[v1] < size[v2]) swap(v1, v2);
		anc[v2] = v1;
		size[v1] += size[v2];
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, n, m1, m2, c1, c2, ans, e[N][2];
	dsu<N> dsu1, dsu2;
	cin >> TC;
	while (TC--) {
		ans = 0;
		cin >> n >> m1 >> m2;
		c1 = c2 = n;
		for (int i = 0; i < m1; ++i) {
			cin >> e[i][0] >> e[i][1];
			--e[i][0], --e[i][1];
		}
		dsu1.init(n);
		dsu2.init(n);
		for (int i = 0, u, v; i < m2; ++i) {
			cin >> u >> v;
			c2 -= dsu2.merge(u - 1, v - 1);
		}
		for (int i = 0; i < m1; ++i) {
			if (dsu2.find(e[i][0]) != dsu2.find(e[i][1])) {
				++ans;
				continue;
			}
			c1 -= dsu1.merge(e[i][0], e[i][1]);
		}
		cout << ans + c1 - c2 << '\n';
	}
}
