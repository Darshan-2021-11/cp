#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int64_t TC = 1, n, b[N], bn, se, cnt[2], mx, t, ans;
	cin >> TC;
	while (TC--) {
		mx = LLONG_MIN;
		cnt[0] = cnt[1] = 0;
		se = bn = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> t;
			if (t & 1) b[bn++] = t, ++cnt[1];
			else se += t, ++cnt[0];
			mx = max(mx, t);
		}
		sort(b, b + bn);
		if (cnt[0] && cnt[1]) {
			--bn;
			ans = se;
			ans += b[bn--];
			while (~bn) ans += b[bn--] - 1;
		} else if (cnt[0]) ans = mx;
		else ans = mx;
		cout << ans << '\n';
	}
}
