#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 500'000;
	int64_t inv;
	int TC = 1, n, x, k, cnt0;
	char a[N];
	cin >> TC;
	while (TC--) {
		inv = cnt0 = 0;
		cin >> n >> x >> k;
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = n - 1; ~i; --i) {
			if (a[i] == '1') inv += cnt0;
			else ++cnt0;
		}
		if (inv <= x && inv % k == 0) cout << 1 << '\n';
		else cout << 2 << '\n';
	}
}
