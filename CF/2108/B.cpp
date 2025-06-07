#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n, x, pop;
	cin >> TC;
	while (TC--) {
		cin >> n >> x;
		if (n == 1) {
			cout << (x ? x : -1) << '\n';
		}
		else if (x == 0) {
			cout << (n & 1 ? n + 3 : n) << '\n';
		}
		else if (x == 1) {
			cout << (n & 1 ? n : n + 3) << '\n';
		}
		else if (!(x & (x - 1))) {
			cout << x + n - (n & 1) << '\n';
		} else {
			pop = __builtin_popcount(x);
			if (n <= pop) {
				cout << x << '\n';
			} else {
				n -= pop;
				cout << x + max(n + (n & 1) - pop, 0) << '\n';
			}
		}
	}
}
