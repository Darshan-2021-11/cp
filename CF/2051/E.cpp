#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, a[N], b[N], n, k, i, j;
	int64_t mx;
	cin >> TC;
	while (TC--) {
		cin >> n >> k;
		for (i = 0; i < n; ++i) cin >> a[i];
		for (i = 0; i < n; ++i) cin >> b[i];
		sort(a, a + n);
		sort(b, b + n);
		i = j = 0;
		mx = static_cast<int64_t>(a[i++]) * n;
		while (i != n) {
			while (b[j] < a[i]) {
				if (i - j <= k) mx = max(mx, static_cast<int64_t>(n - j) * b[j]);
				++j;
				while (j < i && b[j] == b[j - 1]) ++j;
			}
			if (i - j <= k) mx = max(mx, static_cast<int64_t>(n - j) * a[i]);
			++i;
			while (i < n && a[i] == a[i - 1]) ++i;
		}
		while (j != n) {
			if (i - j <= k) mx = max(mx, static_cast<int64_t>(n - j) * b[j]);
			++j;
			while (j < i && b[j] == b[j - 1]) ++j;
		}
		cout << mx << '\n';
	}
}
