#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int64_t ans, x;
	int TC = 1, n, a[N], t;
	map<int64_t, int64_t> m, m0;
	map<int64_t, int64_t>::iterator it;
	cin >> TC;
	while (TC--) {
		t = ans = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			t ^= a[i];
			it = m.find(t);
			if (it != m.end()) {
				x = it->second + a[i];
				m.erase(it);
				m0[a[i]] = x;
			} else {
				it = m0.find(a[i]);
				if (it != m0.end()) {
					x = it->second + a[i];
					m0.erase(it);
					m[a[i]] = x;
				} else {
					m0[t] = a[i];
				}
			}
			cout << "X: ";
			for (const auto &[j, k]: m) cout << j << ',' << k << ' ';
			cout << "\n0: ";
			for (const auto &[j, k]: m0) cout << j << ',' << k << ' ';
			cout << '\n';
		}
		for (const auto &[i, j]: m) ans = max(ans, j);
		for (const auto &[i, j]: m0) ans = max(ans, j);
		cout << ans << '\n';
		cout << '\n';
		m.clear();
		m0.clear();
	}
}
