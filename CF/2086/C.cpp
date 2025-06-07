#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 100'001;
	int TC = 1, n, a[N], q;
	set<int> s;
	cin >> TC;
	while (TC--) {
		s.clear();
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		for (int i = 1, x; i <= n; ++i) {
			cin >> q;
			s.insert(q);
			x = q;
			while (a[q] != x && !s.count(a[q])) {
				q = a[q];
				s.insert(q);
			}
			cout << s.size() << ' ';
		}
		cout << '\n';
	}
}
