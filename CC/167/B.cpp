#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 100;
	int TC = 1, n, cnt0;
	char a;
	cin >> TC;
	while (TC--) {
		cnt0 = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a, cnt0 += a == '0';
		if (cnt0 == n || cnt0 == 0) cout << n << '\n';
		else cout << 1 << '\n';
	}
}
