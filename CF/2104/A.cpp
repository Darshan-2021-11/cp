#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, a, b, c;
	cin >> TC;
	while (TC--) {
		cin >> a >> b >> c;
		cout << (a + c - b >= b && !((c - (b << 1) + a) % 3) ? "YES\n" : "NO\n");
	}
}
