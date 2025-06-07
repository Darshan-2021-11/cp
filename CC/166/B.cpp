#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	int64_t res = 0;
	int TC = 1, n;
	cin >> TC;
	while (TC--) {
		res = 0;
		map<int, int> m;
		cin >> n;
		for (int i = 1, x; i <= n; ++i) {
			cin >> x;
			m[x] = max(m[i], i);
		}
		for (const auto &i: m) res += i.second;
		cout << res << '\n';
	}
}
