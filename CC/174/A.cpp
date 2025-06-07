#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, n, t, a[N];
	cin >> TC;
	while (TC--) {
		cin >> n;
		map<int, int> m;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			++m[a[i]];
		}
		m[0];
		for (auto it = m.rbegin(); it != m.rend(); ++it) {
			if (it->first != 0) {
			t = (it->second) >> 1;
			n -= t;
			m[0] += t;
			} else n -= m[0] ? m[0] - 1 : 0;
		}
		cout << n << '\n';
	}
}
