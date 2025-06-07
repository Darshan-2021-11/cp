#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int64_t cost;
	int TC = 1, n, a[N];
	cin >> TC;
	while (TC--) {
		cost = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n; ++i) {
			cost += max(0, a[i] - i);
		}
		cout << cost << '\n';
	}
}
