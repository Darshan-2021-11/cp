#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int64_t sum;
	int TC = 1, n, a[N], nxt[N], t;
	cin >> TC;
	while (TC--) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		t = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] > a[t]) t = i;
			nxt[i] = t;
		}
		sum = 0;
		for (int i = n - 1; ~i; --i) {
			sum += a[nxt[i]];
			cout << sum << ' ';
			sum -= a[nxt[i]];
			sum += a[i];
		}
		cout << '\n';
	}
}
