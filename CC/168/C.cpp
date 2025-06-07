#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, n, ans, a[N], e, cnt;
	array<int, 2> b[N];
	cin >> TC;
	while (TC--) {
		ans = cnt = 0;
		e = -1;

		cin >> n;
		for (int i = 0; i < n; ++i) b[i][0] = -1;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			--a[i];
			if (b[a[i]][0] == -1) b[a[i]][0] = b[a[i]][1] = i;
			else b[a[i]][1] = i;
		}
		sort(b, b + n);
		for (int i = 0; i < n; ++i) {
			if (b[i][0] == -1) continue;
			if (b[i][0] > e) {
				ans += cnt;
				if (b[i][0] == b[i][1]) cnt = 0, e = -1;
				else cnt = 1, e = b[i][1];
			} else if (b[i][0] < e) {
				++cnt;
				e = max(e, b[i][1]);
			}
		}
		ans += cnt;
		cout << ans << '\n';
	}
}
