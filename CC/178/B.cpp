#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, N, K, a, b;
	cin >> TC;
	while (TC--) {
		cin >> N >> K;
		a = N - !(N & 1), b = 2;
		if (a - b >= K && a * b >= (K << 1)) cout << a << ' ' << b << '\n';
		else cout << -1 << ' ' << -1 << '\n';
	}
}
