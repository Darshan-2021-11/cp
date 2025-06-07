#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 20;
	int TC = 1, n, a[N], mp[10], ans;
	cin >> TC;
	while (TC--) {
		fill_n(mp, 10, 0);
		ans = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for (int i = 0; i < n; ++i) {
			++mp[a[i]];
			if (mp[0] >= 3 && mp[1] >= 1 && mp[2] >= 2 && mp[3] >= 1 && mp[5] >= 1) {
				ans = i + 1;
				break;
			}
		}
		cout << ans << '\n';
	}
}
