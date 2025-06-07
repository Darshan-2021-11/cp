#include <bits/stdc++.h>
using namespace std;

bool f(int n) {
	if (n % 33 == 0) return true;
	bool ans = false;
	string s = to_string(n);
	for (int i = 0; i < (int)s.size() - 1; ++i) {
		if (s[i] == '3' && s[i + 1] == '3') {
			string p = s;
			p.erase(i, 2);
			ans |= f(stoi(p));
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n;
	cin >> TC;
	while (TC--) {
		cin >> n;
		cout << (f(n) ? "YES\n" : "NO\n");
	}
}
