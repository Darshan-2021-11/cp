#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n, m, p, q, v;
	const char *ans[2] = { "NO\n", "YES\n" };
	cin >> TC;
	while (TC--) {
		v = 0;
		cin >> n >> m >> p >> q;
		v = n % p == 0 ? q * (n / p) == m : 1;
		cout << ans[v];
	}
}
