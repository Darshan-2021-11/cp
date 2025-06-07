#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'001;
	int TC = 1, n, m, a[N], b[N];
	cin >> TC;
	while (TC--) {
		bool ans = true;
		cin >> n >> m;
		for (int i = 0; i < n; ++i) cin >> a[i];
		a[n] = 1e9;
		for (int i = 0; i < m; ++i) cin >> b[i];
		sort(b, b + m);
		for (int i = n; i; --i) {
			auto it = lower_bound(b, b + m, a[i] + a[i - 1]);
			if (it == b + m) --it;
			else if (*it > a[i] + a[i - 1]) {
				if (it != b) --it;
				else continue;
			}
			int t = *it - a[i - 1];
			if (t <= a[i] && a[i - 1] <= a[i]) a[i - 1] = max(t, a[i - 1]);
			else if (t <= a[i]) a[i - 1] = t;
		}
		for (int i = 1; i < n; ++i) {
			if (a[i] < a[i - 1]) { ans = false; break; }
		}
print:
		cout << (ans ? "YES\n": "NO\n");
	}
}
