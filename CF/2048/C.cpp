#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int TC = 1, n, s;
	cin >> TC;
	string a;
	while (TC--) {
		s = -1;
		cin >> a;
		n = a.size();

		for (int i = 0; i < n; ++i) if (a[i] == '0') { s = i; break; }
		if (s == -1) {
			cout
				<< 1 << ' ' << n << ' '
				<< n << ' ' << n << '\n';
			continue;
		}
		vector<int> v1, v2;
		for (int i = 0; i + s < n; ++i) {
			v1.push_back(a[i] != a[s + i]);
		}
		int mx = 0;
		for (int i = 1; i < s; ++i) {
			v2.clear();
			for (int j = 0; j + s < n; ++j) {
				v2.push_back(a[i + j] != a[s + j]);
			}
			for (int j = 0; s + j < n; ++j) {
				if (v2[j] && !v1[j]) { v1 = v2, mx = i; break; }
				else if (v2[j] == v1[j]) continue;
				else break;
			}
		}
		cout
			<< 1 << ' ' << n << ' '
			<< mx + 1 << ' ' << mx + n - s << '\n';
	}
}
