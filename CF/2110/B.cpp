#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, n, cnt[2];
	string s;
	bool oac;
	cin >> TC;
	while (TC--) {
		oac = false;
		fill_n(cnt, 2, 0);
		cin >> s;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(') oac |= (cnt[1] == cnt[0]) && i, ++cnt[0];
			else ++cnt[1];
		}
		cout << (oac ? "YES\n": "NO\n");
	}
}
