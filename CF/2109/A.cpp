#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n, sum;
	char p, c, pos;
	cin >> TC;
	while (TC--) {
		sum = 0, pos = true;
		cin >> n;
		cin >> p;
		sum += (p ^= '0');
		for (int i = 1; i < n; ++i) {
			cin >> c;
			sum += (c ^= '0');
			if (!(c | p)) pos = false;
			p = c;
		}
		cout << (pos && sum < n ? "NO\n" : "YES\n");
	}
}
