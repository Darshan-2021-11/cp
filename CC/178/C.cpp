#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, a[N], n, b[32];
	const char ans[2] = { '0', '1' };
	bool inc;
	cin >> TC;
	while (TC--) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		if (n > 31) {
			for (int i = 0; i < n; ++i) cout << '0';
			cout << '\n';
			continue;
		}
		if (n == 2) {
			cout << "11\n";
			continue;
		}
		for (int i = 0, j, k, l = 0, p; i < n; ++i) {
			for (j = k = 0; j < n; ++j) {
				if (i == j) continue;
				b[k++] = a[j];
			}
			inc = true, p = 0;
			for (j = k; j > 1; --j) {
				p = 0;
				for (l = 0; l < j; ++l) {
					if (b[l] > p) {
						p = b[l];
						b[l] = b[l + 1] - b[l];
					} else {
						inc = false;
						break;
					}
				}
				if (!inc) {
					break;
				}
			}
			inc &= b[0] > 0;
			cout << ans[inc];
		}
		cout << '\n';
	}
}
