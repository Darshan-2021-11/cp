#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 300'000;
	int TC = 1, n;
	array<int64_t, 2> a[N];
	set<int64_t> s;
	set<int64_t>::iterator it;
	cin >> TC;
	while (TC--) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i][0], a[i][0] += i, a[i][1] = i;
		sort(a, a + n);
		s.insert(n);
		for (int i = 0; i < n; ++i) {
			if (s.find(a[i][0]) == s.end())
				continue;
			s.insert(a[i][0] + a[i][1]);
		}
		cout << *s.rbegin() << '\n';
		s.clear();
	}
}
