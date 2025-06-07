#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, n, v, b[N << 1], bn;
	string s, t;
	s.reserve(N), t.reserve(N);
	cin >> TC;
	while (TC--) {
		v = INT_MIN, bn = 0;
		cin >> n >> s >> t;
		if (s == t) {
			cout << 0 << '\n';
			continue;
		}

		for (int i = 0; i < n; ++i) {
			if (t[i] == '0' && s[i] == '0') continue;
			v = i;
			break;
		}
		if (s[v] != t[v]) {
			cout << -1 << '\n';
			continue;
		}
		++v;
		for (int i = v; i < n; ++i) {
			if (s[i] != '1') {
				b[bn++] = i, s[i] = '1';
			}
		}
		--v;
		for (int i = n - 1; i > v; --i) {
			if (s[i] != t[i])
				b[bn++] = i;
		}
		cout << bn << '\n';
		for (int i = 0; i < bn; ++i) cout << b[i] << ' ';
		cout << '\n';
	}
}
