#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 2000;
	int TC = 1, n, a[N], s, e, inv, tinv, stinv;
	cin >> TC;
	while (TC--) {
		inv = 0;
		s = e = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) {
			tinv = 0;
			for (int j = 0; j < i; ++j) tinv += a[j] > a[i];
			for (int j = i + 1; j < i; ++j) tinv += a[j] < a[i];
			stinv = tinv;
			for (int j = i; j < n; ++j) {
				if (a[i] == a[j]) continue;
				else if (a[i] < a[j]) ++tinv;
				else --tinv;

				if (stinv - tinv > inv) {
					inv = stinv - tinv;
					s = i, e = j;
				}
			}
		}
		cout << s + 1 << ' ' << e + 1 << '\n';
	}
}
