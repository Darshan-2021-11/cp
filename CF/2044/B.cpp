#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1;
	cin >> TC;
	while (TC--) {
		string s;
		cin >> s;
		for (auto &i: s) {
			if (i == 'w') continue;
			i ^= 'p' ^ 'q';
		}
		reverse(s.begin(), s.end());
		cout << s << '\n';
	}
}
