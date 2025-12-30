#include <bits/stdc++.h>
using namespace std;

double sq(double v) {
	double l = 0, r = max(1.0, v), x;
	for (int j = 0; j < 60; ++j) {
		x = (l + r) / 2;
		if (x * x > v) r = x;
		else l = x;
	}
	return l;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	const int N = 1;
	int TC = 1;
	double l, r, x, c;
	//cin >> TC;
	while (TC--) {
		cin >> c;
		l = 0, r = 1e5;
		for (int j = 0; j < 60; ++j) {
			x = (l + r) / 2;
			if (x * x + sq(x) >= c) r = x;
			else l = x;
		}
		cout << setprecision(7) << r << '\n';
	}
}
