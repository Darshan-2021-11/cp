#include <bits/stdc++.h>
using namespace std;

int inv(int a) {
	const int m = 2;
  return a <= 1 ? a : m - (long long)(m/a) * inv(m % a) % m;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n, k;
	cin >> TC;
	while (TC--) {
		cin >> n >> k;
		--n;
		cout << k << ' ';
		for (int i = 1; i <= n; ++i) {
			cout << ((n & i) == i ? k : 0) << ' ';
		}
		cout << '\n';
	}
}
