#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 100'000;
	int TC = 1, n, k, a[N], ans;
	map<int, int> m;
	map<int, int>::iterator it;
	cin >> TC;
	while (TC--) {
		cin >> n >> k;
		for (int i = 0, t; i < n; ++i) cin >> t, ++m[t];
		it = m.begin();
		for (int i = 0; it != m.end(); ++it) {
			a[i++] = it->second;
		}
		ans = m.size();
		sort(a, a + m.size(), greater<int>());
		int x = a[0];
		for (int i = 1; i < m.size(); ++i) {
			if (n - x <= k) {
				ans = i;
				break;
			}
			x += a[i];
		}
		cout << ans << '\n';
		m.clear();
	}
}
