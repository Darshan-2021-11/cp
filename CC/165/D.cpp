#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 300'000;
	int TC = 1, n, a[N], res, p, t;
	cin >> TC;
	while (TC--) {
		res = t = p = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for (int i = n - 1; ~i; --i) {
			if (p <= a[i]) res = max(res, t), p = a[i], t = 0;
			else ++t;
		}
		res = max(res, t);
		cout << res << '\n';
	}
}
