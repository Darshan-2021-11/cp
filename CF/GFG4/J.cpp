#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1;
	cin >> TC;
	while (TC--) {
		int64_t n;
		cin >> n;
		cout << __builtin_popcountll(n) << '\n';
	}
}
