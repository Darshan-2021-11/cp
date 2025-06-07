#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 50;
	int TC = 1, n, a[N], cnt0, ans;
	cin >> TC;
	while (TC--) {
		cnt0 = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i], cnt0 += a[i] == 0;
		}
		int c[2]{};
		for (int i = 0; i < n; ++i) if (a[i] == 0) ++c[0]; else break;
		for (int i = n - 1; ~i; --i) if (a[i] == 0) ++c[1]; else break;
		if (cnt0 == n) ans = 0;
		else if (cnt0 -c[0]-c[1]== 0) ans = 1;
		else ans = 2;
		cout << ans << '\n';
	}
}
