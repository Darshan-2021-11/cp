#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n, k;
	cin >> TC;
	while (TC--) {
		cin >> n >> k;
		for (int i = 1, t; i <= n; ++i) {
			if (i != n - 1) t = k & 1 ? n : n - 1;
			else t = k & 1 ? n - 1 : n;
			if (t == i) t + 1 > n ? --t : ++t;
			cout << t << ' ';
		}
		cout << '\n';
	}
}
