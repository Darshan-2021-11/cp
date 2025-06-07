#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n, sum;
	cin >> TC;
	while (TC--) {
		sum = 0;
		cin >> n;
		for (int i = 1, t = n; i <= n; ++i, --t) sum += abs(t - i);
		cout << (sum >> 1) + 1 << '\n';
	}
}
