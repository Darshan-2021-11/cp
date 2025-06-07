#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1;
	int64_t ans, n;
	cin >> TC;
	while (TC--) {
		ans = 0;
		cin >> n;
		for (int i = 0; i <= n >> 1; ++i) ans += i * (n - i) + 1;
		cout << ans << '\n';
	}
}
