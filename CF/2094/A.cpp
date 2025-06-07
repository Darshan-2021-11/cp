#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1;
	cin >> TC;
	while (TC--) {
		for (int i = 0; i <= 2; ++i) {
			string s;
			cin >> s;
			cout << s[0];
		}
		cout << '\n';
	}
}
