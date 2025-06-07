#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int64_t ans, u;
	int TC = 1, n, m, t, tmex, mex, cnt, a[N];
	cin >> TC;
	while (TC--) {
		ans = u = mex = 0;
		cin >> n >> m;
		while (n--) {
			cin >> t;
			tmex = -1, cnt = 0;
			for (int i = 0; i < t; ++i) cin >> a[i];
			sort(a, a + t);
			t = unique(a, a + t) - a;
			for (int i = 0; i - cnt < t; ++i) {
				if (a[i - cnt] == i) continue;
				++cnt;
				if (cnt != 2) continue;
				tmex = i;
				break;
			}
			if (tmex == -1) tmex = a[t - 1] + 2 - cnt;
			mex = max(mex, tmex);
		}
		ans = mex;
		ans *= m + 1;
		if (m > mex) {
			u = m - mex;
			u *= u + 1;
			u >>= 1;
		}
		cout << ans + u << '\n';
	}
}
