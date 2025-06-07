#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 1000;
	int TC = 1, n, an;
	char a[N];
	cin >> TC;
	while (TC--) {
		an = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[an];
			if (an && a[an - 1] == a[an]) --an;
			++an;
		}
		cout << an - (a[0] == '0') << '\n';
	}
}
