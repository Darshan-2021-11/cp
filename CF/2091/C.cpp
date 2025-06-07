#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'001;
	int TC = 1, n, a[N], b[N];
	bool pos;
	cin >> TC;
	while (TC--) {
		pos = true;
		cin >> n;
		for (int i = 1, t; i <= n; ++i) {
			t = ((i << 1) - 1) % n;
			a[t == 0 ? n : t] = i;
		}
		for (int i = 1; i <= n; ++i) {
			b[i] = a[i];
		}
		sort(b + 1, b + n + 1);
		for (int i = 1; i <= n; ++i) pos &= b[i] == i;
		if (!pos) {
			cout << -1 << '\n';
			continue;
		}
		for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
		cout << '\n';
	}
}
