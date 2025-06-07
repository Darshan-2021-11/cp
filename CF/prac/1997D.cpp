#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, n, head[N], nxt[N], a[N];

	const auto dfs = [&](auto self, int c) -> void {
		int mn = INT_MAX, t;
		t = head[c];
		while (t) {
			self(self, t);
			mn = min(mn, a[t]);
			t = nxt[t];
		}
		if (mn == INT_MAX) return;
		if (!c) {
			a[c] += mn;
			return;
		}
		if (mn > a[c]) a[c] += (mn - a[c]) >> 1;
		else a[c] = mn;
	};

	cin >> TC;
	while (TC--) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i], head[i] = 0;
		for (int i = 1, u; i < n; ++i) {
			cin >> u;
			--u;
			nxt[i] = head[u], head[u] = i;
		}
		dfs(dfs, 0);
		cout << a[0] << '\n';
	}
}
