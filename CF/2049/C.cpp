#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, a[N], n, x, y;
	cin >> TC;
	while (TC--) {
		cin >> n >> x >> y;
		--x, --y;
		for (int i = 0; i < n; ++i) a[(x + i) % n] = i & 1;
		if ((n & 1) || !((x - y) & 1)) a[x] = 2;
		for (int i = 0; i < n; ++i) cout << a[i] << ' ';
		cout << '\n';
	}
}
