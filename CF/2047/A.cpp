#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n, m;
	cin >> TC;
	while (TC--) {
		cin >> n >> m;
		cout << max(n, m) + 1 << '\n';
	}
}
