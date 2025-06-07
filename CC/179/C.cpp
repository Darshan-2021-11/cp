#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, n, k, a[N], b[N], ops, mn;
	cin >> TC;
	while (TC--) {
		ops = 0, mn = INT_MAX;
		cin >> n >> k;
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0, u, v; i < n; ++i) {
			cin >> b[i];
			if (b[i] > a[i]) swap(a[i], b[i]);
			u = a[i] - b[i], v = 9 + b[i] - a[i];
			if (u < v) ops += u, mn = min(mn, v);
			else ops += v, mn = min(mn, u);
		}
		if (k >= ops && (!((k - ops) & 1) || (ops - (9 - mn) + mn) <= k))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
