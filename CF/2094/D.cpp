#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1;
	cin >> TC;
	string s[2];
	int j;
	char c;
	bool pos;
	while (TC--) {
		pos = true;
		cin >> s[0] >> s[1];
		vector<int> p[2];
		c = -1;
		j = 0;
		for (int i = 0; i < (int)s[0].size(); ++i) {
			if (s[0][i] == c) ++j;
			else p[0].emplace_back(j), c = s[0][i], j = 1;
		}
		p[0].emplace_back(j);
		c = -1;
		j = 0;
		for (int i = 0; i < (int)s[1].size(); ++i) {
			if (s[1][i] == c) ++j;
			else p[1].emplace_back(j), c = s[1][i], j = 1;
		}
		p[1].emplace_back(j);
		if (s[0][0] != s[1][0] || p[0].size() != p[1].size()) {
			cout << "NO\n";
			continue;
		}
		for (int i = 0; i < (int)p[0].size(); ++i) {
			pos &= (p[0][i] <= p[1][i]) && (p[1][i] <= p[0][i] * 2);
		}
		cout << (pos ? "YES\n": "NO\n");
	}
}
