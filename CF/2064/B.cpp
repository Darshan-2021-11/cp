#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, n, a[N], mp[N], cnt, cnt1, mn, mx, idx;
	cin >> TC;
	while (TC--) {
		idx = -1;
		mx = 0;
		mn = INT_MAX;
		cnt = cnt1 = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) mp[i] = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			++mp[--a[i]];
		}
		for (int i = 0; i < n; ++i) {
			if (!mp[i]) continue;
			mn = min(mp[i], mn);
			cnt1 += mp[i] == 1;
		}
		if (mn == 1) {
			for (int i = 0; i < n; ++i) {
				if (mp[a[i]] == 1) ++cnt;
				else {
					if (cnt > mx) mx = cnt, idx = i - cnt;
					cnt = 0;
				}
			}
			if (cnt > mx) mx = cnt, idx = n - cnt;
			cout << idx + 1 << ' ' << idx + mx << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
}
