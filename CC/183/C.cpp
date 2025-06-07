#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n, mx, mn;
	cin >> TC;
	while (TC--) {
		cin >> n;
		mn = INT_MAX, mx = INT_MIN;
		for (int i = 0, t; i < n; ++i) {
			cin >> t;
			mn = min(mn, t);
			mx = max(mx, t);
		}
		cout << max(0, mx - mn - 1) << '\n';
	}
}
