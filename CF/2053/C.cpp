#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int64_t ans, n, k, s[32], sn, cnt;
	int TC = 1;
	cin >> TC;
	while (TC--) {
		ans = sn = cnt = 0;
		cin >> n >> k;
		s[sn++] = n;
		while (n >= k)
			s[sn++] = (n >>= 1);
		while (--sn) {
			ans <<= 1;
			if (s[sn - 1] & 1) ans += (cnt + 1) * (s[sn] + 1);
			else ans += cnt * s[sn];
			cnt <<= 1;
			cnt += s[sn - 1] & 1;
		}
		cout << ans << '\n';
	}
}
