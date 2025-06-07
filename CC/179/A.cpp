#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, x, y;
	while (TC--) {
		cin >> x >> y;
		cout << (x >= y * 10 ? "YES\n" : "NO\n");
	}
}
