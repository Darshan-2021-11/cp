#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n;
	string s;
	char t;
	cin >> TC;
	while (TC--) {
		cin >> s >> n;
		for (const auto &i: s) {
			t = i - 'a' + n;
			if (t > 25) t -= 26;
			cout << (char)(t + 'a');
		}
		cout << '\n';
	}
}
