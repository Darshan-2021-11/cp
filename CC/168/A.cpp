#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 20;
	int TC = 1, n, mx, mn;
	char a[2][N];
	cin >> TC;
	while (TC--) {
		mx = mn = 0;
		cin >> n;
		for (int j = 0; j < 2; ++j) for (int i = 0; i < n; ++i) cin >> a[j][i];
		for (int i = 0; i < n; ++i) mx += max(a[0][i], a[1][i]) ^ '0', mn += min(a[0][i], a[1][i]) ^ '0';
		cout << (mx & 1 || mn & 1 || mx - mn ? "YES\n" : "NO\n");
	}
}
