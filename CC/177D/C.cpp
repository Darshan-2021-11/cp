#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 100;
	int TC = 1, n, b[N], idx;
	array<int, 2> c[N];
	cin >> TC;
	while (TC--) {
		idx = -1;
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> c[i][1];
		for (int i = 0; i < n; ++i) cin >> b[i];
		for (int i = 0; i < n; ++i) {
			if (c[i][1] == b[0]) idx = i + 1;
			c[i][0] = abs(b[0] - c[i][1]);
		}
		if (idx == -1) goto print;
		sort(c, c + n);
		for (int i = 0; i < n; ++i) {
			if (c[i][1] == b[i]) continue;
			idx = -1;
			break;
		}
print:
		cout << idx << '\n';
	}
}
