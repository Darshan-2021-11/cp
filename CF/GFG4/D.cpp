#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 101;
	int TC = 1, n, cnt, sz[N];
	bool yes;
	cin >> TC;
	while (TC--) {
		yes = true, cnt = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i) sz[i] = 0;
		for (int u, v, i = 1; i < n; ++i) {
			cin >> u >> v;
			++sz[u], ++sz[v];
		}
		for (int i = 1; i <= n; ++i) {
			yes &= sz[i] < 3;
			cnt += sz[i] == 1;
		}
		cout << (yes && cnt < 3 ? "YES\n": "NO\n");
	}
}
