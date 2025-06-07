#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1;
	cin >> TC;
	while (TC--) {
		string s;
		bool b = true;
		cin >> s;
		while (b && s.size() > 1) {
			b = false;
			for (int i = s.size() - 2; i >= 0; --i) {
				if (s[i] == s[i + 1]) {
					s.erase(i + 1);
					if (i) s[i] = s[i - 1];
					else b = true;
				}
			}
			reverse(s.begin(), s.end());
		}
		cout << s.size() << '\n';
	}
}
