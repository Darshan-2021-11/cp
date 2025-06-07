#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, n, k, v[2], res;
	cin >> TC;
	while (TC--) {
		res = 0;
		v[0] = v[1] = -1;
		cin >> n >> k;
		for (int i = 0, t, u; i < n; ++i) {
			cin >> t >> u;
			v[t - 1] = max(v[t - 1], u);
		}
		if (v[0] == -1) {
			cout << ((k - 1) / v[1] + 1) * 2 << '\n';
			continue;
		}
		if (v[1] == -1) {
			cout << (k - 1) / v[0] + 1 << '\n';
			continue;
		}
		if (v[0] >= k) {
			cout << 1 << '\n';
			continue;
		}
		if (v[1] >= k) {
			cout << 2 << '\n';
			continue;
		}
		if (v[1] <= v[0]) {
			cout << (k - 1) / v[0] + 1 << '\n';
			continue;
		}
		res += (k / v[1]) * 2;
		k %= v[1];
		cout << (k <= v[0] ? res + 1 : res + 2) << '\n';
	}
}
