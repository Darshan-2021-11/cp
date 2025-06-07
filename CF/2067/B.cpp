#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 1'000;
	int TC = 1, mp[N], n, req, t;
	cin >> TC;
	while (TC--) {
		cin >> n;
		fill_n(mp, N, 0);
		for (int i = 0; i < n; ++i) {
			cin >> t;
			++mp[t - 1];
		}
		req = 0;
		for (int i = N - 1; ~i; --i) {
			if (req == 0) {
				if (mp[i] & 1) --req;
				else continue;
			} else {
				if (mp[i] > 2) {
					t = min(abs(req), mp[i] - 2);
					req += t;
					mp[i] -= t;
					if (mp[i] & 1) ++i;
				} else req -= 2 - mp[i];
			}
		}
		cout << (!req ? "YES\n" : "NO\n");
	}
}
