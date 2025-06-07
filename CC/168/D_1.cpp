#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int64_t ans, x;
	int TC = 1, n, nm, a[N], t;
	array<int64_t, 2> m[N];
	cin >> TC;
	while (TC--) {
		t = ans = nm = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			x = nm;
			cin >> a[i];
			for (int j = 0; j < nm; ++j) {
				if (m[j][0] == a[i]) x = j;
				else m[j][0] ^= a[i];
			}
			if (x != nm) m[x][1] += m[x][0];
			else m[nm++] = { a[i], a[i] };
		}
		for (int i = 0; i < nm; ++i) ans = max(ans, m[i][1]);
		cout << ans << '\n';
	}
}
