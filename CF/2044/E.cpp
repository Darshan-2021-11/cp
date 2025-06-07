#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int64_t km, ans, TC = 1, k, l1, l2, r1, r2;
	int s, e;
	cin >> TC;
	while (TC--) {
		ans = 0;
		cin >> k >> l1 >> r1 >> l2 >> r2;
		km = 1;
		while (r2 / km >= l1) {
			s = max(l1, (l2 - 1) / km + 1);
			e = min(r1, r2 / km);
			if (e >= s) ans += e - s + 1;
			km *= k;
		}
		cout << ans << endl;
	}
}
