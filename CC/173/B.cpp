#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'001;
	int TC = 1, n, a[N];
	cin >> TC;
	while (TC--) {
		cin >> n;
		map<int, int> mp;
		for (int i = 0; i < n; ++i) cin >> a[i], ++mp[a[i]];
		bool found = false;
		for (const auto &i: mp) {
			if (i.second > 1) {
				found = true;
				cout << 1 << '\n' << i.first << '\n';
				break;
			}
		}
		if (!found) cout << -1 << '\n';
	}
}
