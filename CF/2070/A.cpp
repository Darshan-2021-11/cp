#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n;
	cin >> TC;
	while (TC--) {
		cin >> n;
		cout << (n / 15) * 3 + min(n % 15 + 1, 3) << '\n';
	}
}
