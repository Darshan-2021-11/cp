#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'000;
	int TC = 1, n, t, mn;
	map<int, int> m;
	map<int, int>::iterator it;
	mn = INT_MAX;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		if ((it = m.find(t)) == m.end()) {
			m[t] = i;
		} else {
			mn = min(mn, i - m[t] + 1);
			m[t] = i;
		}
	}
	cout << (mn > n ? -1 : mn);
}
