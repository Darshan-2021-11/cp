#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'005;
	int TC = 1, n, a[N];
	cin >> TC;
	while (TC--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		sort(a + 1, a + n + 1, greater<int>());
		while (n > 1) {
			a[n - 1] = a[n] + a[n - 1] - 1;
			if (!(--n)) break;
		}
		cout << a[1] << '\n';
	}
}
