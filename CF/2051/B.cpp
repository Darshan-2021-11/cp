#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n, a, b, c, x, res;
	cin >> TC;
	while (TC--) {
		cin >> n >> a >> b >> c;
		x = (a + b + c);
		res = n / x;
		n -= res * x;
		res *= 3;
		if (n > 0) ++res, n -= a;
		if (n > 0) ++res, n -= b;
		if (n > 0) ++res, n -= c;
		cout << res << '\n';
	}
}
