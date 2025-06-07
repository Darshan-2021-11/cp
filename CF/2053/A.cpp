#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200;
	int TC = 1, n, a[N];
	cin >> TC;
	while (TC--) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 1; i < n; ++i) {
			if (min(a[i - 1], a[i]) << 1 > max(a[i], a[i - 1])) goto yes;
		}
		goto no;
yes:
		cout << "YES\n";
		 continue;
no:
		 cout << "NO\n";
	}
}
