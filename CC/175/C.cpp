#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	map<int, int> m;
	int TC = 1, a[N], x, n, t, mx, tmx;
	cin >> TC;
	while (TC--) {
		mx = INT_MIN;
		cin >> n >> x;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			++m[a[i]];
		}
		for (const auto &[i, j]: m) mx = max(mx, j);
		if (x == 1) goto print;

		for (const auto &[i, j]: m) {
			t = i / x;
			if (t * x != i || m.find(t) == m.end() || m[i] + m[t] <= mx) continue;
			tmx = 0;
			int cur = 0, mxCur = 0;
			for (int k = 0; k < n; ++k) {
				cur += a[k] == t ? 1 : a[k] == i ? -1 : 0;
				cur = max(cur, 0);
				mxCur = max(mxCur, cur);
			}
			tmx = max(tmx, mxCur);
			mx = max(mx, j + tmx);
		}
print:
		cout << mx << '\n';
		m.clear();
	}
}
