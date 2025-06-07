#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int64_t ans, TC = 1, x1, x2, y1, y2, z1, z2, k, d[3];
	cin >> TC;
	while (TC--) {
		ans = 0;
		cin
			>> x1 >> y1 >> z1
			>> x2 >> y2 >> z2
			>> k;

		d[0] = abs(x1 - x2);
		d[1] = abs(y1 - y2);
		d[2] = abs(z1 - z2);
		sort(d, d + 3);
		for (int i = 0; i < 3; ++i)
			ans += d[i];
		y1 = (d[0] + d[1]) * k;
		if (y1 < d[2]) {
			y2 = d[2] - y1;
			x1 = (y2 - 1) / k + 1;
			ans += x1 - (x1 & 1);
		}
		cout << ans << '\n';
	}
}
