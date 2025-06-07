#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 10;
	int TC = 1, n, cost, tcost, tmp, mn;
	char a[N];
	cin >> TC;
	while (TC--) {
		cin >> n >> cost;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		mn = INT_MAX;
		for (int i = 0, x; i <= 32; ++i) {
			x = i;
			tcost = 0;
			while (x) tcost += x & 1, x >>= 1;
			tcost *= cost;
			tmp = 0;
			for (int j = 0; j < n; ++j) {
				if (!((1 << (a[j] - 'A')) & i)) {
					tcost += ++tmp;
				}
			}
			mn = min(tcost, mn);
		}
		cout << mn << '\n';
	}
}
