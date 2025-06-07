#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 100'000;
	int TC = 1, n, k, a[N];
	cin >> TC;
	while (TC--) {
		cin >> n >> k;
		for (int i = 0; i < n; ++i) cin >> a[i];
		sort(a, a + n);
		cout << a[(k + n) >> 1] - a[(n - k - 1) >> 1] + 1 << '\n';
	}
}
