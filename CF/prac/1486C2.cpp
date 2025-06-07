#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int n, mx_2, res, l, r, x;
	bool left;
	set<array<int, 2>> s;
	cin >> n;
	const auto query = [&](int a, int b) -> void {
		cout << "? " << a << ' ' << b << endl;
		cin >> res;
	};
	query(1, n);
	mx_2 = res;
	if (mx_2 == 1) left = false;
	else if (mx_2 == n) left = true;
	else query(1, mx_2), left = res == mx_2;

	if (left) {
		l = 1, r = mx_2;
		while (r - l > 1) {
			x = l + r >> 1;
			query(x, mx_2);
			if (res == mx_2) l = x;
			else r = x;
		}
		cout << "! " << l << endl;
	} else {
		l = mx_2, r = n;
		while (r - l > 1) {
			x = l + r >> 1;
			query(mx_2, x);
			if (res == mx_2) r = x;
			else l = x;
		}
		cout << "! " << r << endl;
	}
}
