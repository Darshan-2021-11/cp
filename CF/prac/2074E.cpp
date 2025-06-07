#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n, a[3], res;
	mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> ridx(0, 2);
	cin >> TC;
	while (TC--) {
		iota(a, a + 3, 1);
		cin >> n;
		while (true) {
			cout << '?';
			for (int i = 0; i < 3; ++i) cout << ' ' << a[i];
			cout << endl;
			cin >> res;
			if (res < 0) return -1;
			else if (!res) break;
			else {
				a[ridx(rnd)] = res;
			}
		}
		cout << '!';
		for (int i = 0; i < 3; ++i) cout << ' ' << a[i];
		cout << endl;
	}
}
