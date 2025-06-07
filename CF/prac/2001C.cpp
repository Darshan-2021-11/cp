#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n, x, t, a[1000];
	cin >> TC;
	while (TC--) {
		cin >> n;
		for (int i = 2; i <= n; ++i) {
			t = 1;
			while (t != i) {
				x = t;
				cout << "? " << i << ' ' << x << endl;
				cin >> t;
			}
			a[i - 2] = x;
		}
		cout << "! ";
		for (int i = 2; i <= n; ++i) {
			cout << a[i - 2] << ' ' << i << ' ';
		}
		cout << endl;
	}
}
