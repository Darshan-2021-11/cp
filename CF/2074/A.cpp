#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, a[4];
	cin >> TC;
	bool ans;
	while (TC--) {
		ans = true;
		cin >> a[0];
		for (int i = 0; i < 3; ++i) {
			cin >> a[i + 1];
			if (a[i] != a[i + 1]) ans = false;
		}
		cout << (ans ? "YES\n" : "NO\n");
	}
}
