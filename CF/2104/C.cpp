#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 49;
	int TC = 1, n, a[N], an;
	char c;
	cin >> TC;
	while (TC--) {
		cin >> n;
		an = 0;
		for (int i = 0; i < n; ++i) {
			cin >> c;
			if (c == 'A') a[an++] = i;
		}
		if (n == 2) {
			cout << (a[0] ? "Bob\n" : "Alice\n");
		} else if (an == 1 || (a[0] > 0 && a[an - 1] < n - 1)) {
			cout << "Bob\n";
		} else if (n - an == 1) {
			cout << "Alice\n";
		} else if (
				(a[an - 1] == n - 1 && a[0] == 0) ||
				(a[an - 1] == n - 1 && a[an - 2] == n - 2)
				) {
			cout << "Alice\n";
		} else {
			cout << "Bob\n";
		}
	}
}
