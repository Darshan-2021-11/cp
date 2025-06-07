#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 100'000;
	int64_t TC = 1, n, a[N], mn, f, g, t;
	bool found;
	cin >> TC;
	while (TC--) {
		found = false;
		f = g = 0, mn = LLONG_MAX;
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) {
			if (a[i] < mn) mn = a[i], f = 0;
			f += (a[i] == mn);
		}
		if (f > 1) {
			cout << "YES\n";
			continue;
		}
		for (int i = 0; i < n; ++i) {
			if (!found && a[i] == mn) {
				found = true;
				continue;
			}
			t = a[i] / mn;
			if (mn * t != a[i]) continue;
			g = gcd(g, t);
		}
		if (g == 1)
			cout << "YES\n";
		else 
			cout << "NO\n";
	}
}
