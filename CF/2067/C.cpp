#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int64_t p9[9] = {
		9,
		99,
		999,
		9999,
		99999,
		999999,
		9999999,
		99999999,
		999999999,
	};
	int64_t TC = 1, n, nc, ans;
	cin >> TC;
	const auto c7 = [](int64_t x) -> bool {
		while (x) {
			if (x % 10 == 7) {
				return true;
			}
			x /= 10;
		}
		return false;
	};

	while (TC--) {
		cin >> n;
		if (c7(n)) {
			cout << 0 << '\n';
			continue;
		}
		ans = 9;
		for (int i = 0; i < 10; ++i) {
			nc = n;
			for (int64_t j = 1; i < 9; ++j) {
				nc += p9[i];
				if (c7(nc)) {
					ans = min(j, ans);
					break;
				}
			}
		}
		cout << ans << '\n';
	}
}
