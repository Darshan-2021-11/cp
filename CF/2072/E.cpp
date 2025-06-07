#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, k, x, y, an, a[500][2];
	cin >> TC;
	while (TC--) {
		an = x = y = 0;
		cin >> k;
		while (k) {
			a[an][0] = x;
			a[an][1] = y++;
			++an;
			for (int i = 2; i <= 500; ++i) {
				if ((((i - 1) * i) >> 1) <= k) {
					a[an][0] = x;
					a[an][1] = y++;
					++an;
					continue;
				}
				i -= 1;
				k -= (((i - 1) * i) >> 1);
				++x;
				break;
			}
		}
		cout << an << '\n';
		for (int i = 0; i < an; ++i) {
			cout << a[i][0] << ' ' << a[i][1] << '\n';
		}
	}
}
