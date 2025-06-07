#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n, p;
	bool pos;
	map<int, int> mp;
	map<int, int>::iterator it;
	cin >> TC;
	while (TC--) {
		pos = false;
		cin >> n;
		for (int i = 0, t; i < n; ++i) cin >> t, ++mp[t];
		p = -1;
		for (const auto &[i, j]: mp) {
			if (p + 1 == i) {
				if (j > 1) {
					pos = true;
					break;
				}
				p = i;
				continue;
			}
			p = -1;
			if (j > 1) {
				if (j >= 4) {
					pos = true;
					break;
				}
				p = i;
			}
		}
		cout << (pos ? "YES\n" : "NO\n");
		mp.clear();
	}
}
