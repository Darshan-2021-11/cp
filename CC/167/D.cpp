#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 500'000;
	int64_t t, ans;
	int TC = 1, n;
	cin >> TC;
	while (TC--) {
		t = ans = 0;
		cin >> n;
		for (int i = 0, x; i < n; ++i) {
			cin >> x;
			ans += abs(t);
			t += x;
		}
		cout << ans << '\n';
	}
}
