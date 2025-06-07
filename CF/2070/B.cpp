#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, n, x, t, idx;
	char a[N];
	int64_t k, cnt;
	cin >> TC;
	while (TC--) {
		cin >> n >> x >> k;
		idx = -1, t = x, cnt = 0;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		for (int i = 0; i < n; ++i) {
			t += a[i] == 'L' ? -1 : 1;
			if (t == 0) {
				idx = i + 1;
				break;
			}
		}
		if (idx == -1 || idx > k) {
			cout << cnt << '\n';
			continue;
		}
		k -= idx;
		cnt = 1, t = 0, idx = -1;
		for (int i = 0; i < n; ++i) {
			t += a[i] == 'L' ? -1 : 1;
			if (t == 0) {
				idx = i + 1;
				break;
			}
		}
		if (idx == -1) cout << 1 << '\n';
		else cout << 1 + (k / idx) << '\n';
	}
}
