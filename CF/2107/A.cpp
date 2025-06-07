#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 100;
	int TC = 1, n, g, a[N], b[N];
	cin >> TC;
	while (TC--) {
		g = 0;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> a[i], b[i] = a[i];
		sort(a, a + n, greater<int>());
		for (int i = 1; i < n; ++i)
			g = __gcd(g, a[i]);
		if (g == a[0]) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			for (int i = 0; i < n; ++i) {
				if (b[i] == a[0]) cout << 2 << ' ';
				else cout << 1 << ' ';
			}
			cout << '\n';
		}
	}
}
