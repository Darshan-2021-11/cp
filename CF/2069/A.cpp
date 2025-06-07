#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 100;
	int TC = 1, n, a[N];
	bool yes;
	cin >> TC;
	while (TC--) {
		yes = true;
		cin >> n;
		for (int i = 0; i < n - 2; ++i) cin >> a[i];
		n -= 2;
		if (n < 3) {
			cout << "YES\n";
			continue;
		}
		for (int i = 1; i + 1 < n; ++i) {
			if (a[i] == 0 && a[i - 1] == 1 && a[i + 1] == 1) {
				yes = false;
				break;
			}
		}
		cout << (yes ? "YES\n": "NO\n");
	}
}
