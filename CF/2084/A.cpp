#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 101;
	int TC = 1, n, a[N];
	cin >> TC;
	while (TC--) {
		cin >> n;
		if (n & 1) {
			a[0] = n;
			cout << a[0];
			for (int i = 1; i < n; ++i) {
				a[i] = i;
				cout << ' ' << a[i];
				//assert((max(a[i], a[i - 1]) % (i + 1)) == i);
			}
			cout << '\n';
		} else cout << -1 << '\n';
	}
}
