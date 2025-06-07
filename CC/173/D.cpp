#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
	const int N = 200'001;
	int TC = 1, n, a[N], mp[N];
	multiset<int> m;
	set<pair<int, int>> s;
	bool yes;
	cin >> TC;
	while (TC--) {
		yes = true;
		cin >> n;
		if (n == 1) { cin >> a[0]; cout << "YES\n"; continue; }
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			mp[a[i]] = i;
		}
		if (
				(a[0] == 1 && a[n - 1] == 2) ||
				(a[0] == 2 && a[n - 1] == 1)
			 );
		else {
			yes = false;
			goto print;
		}
		m.insert(n - 2);
		s.emplace(n - 2, 1);
		for (int i = 3; i <= n; ++i) {
			int sz = *(--m.end());
			auto it = s.lower_bound({ mp[i], 0 });
			pair<int, int> val = *it;
			int size = val.first - val.second + 1;
			int u1 = val.first - mp[i];
			int u2 = mp[i] - val.second;
			if (sz & 1) {
				if ((size != sz) || abs(u1 - u2) > 0) {
					yes = false;
					goto print;
				}
				s.erase(it);
				s.emplace(val.first, mp[i] + 1);
				s.emplace(mp[i] - 1, val.second);
				auto x = m.find(size);
				m.erase(x);
				m.insert(u1);
				m.insert(u2);
			} else {
				if (((sz - size) > 1) || abs(u1 - u2) > 1) {
					yes = false;
					goto print;
				}
				s.erase(it);
				s.emplace(val.first, mp[i] + 1);
				s.emplace(mp[i] - 1, val.second);
				auto x = m.find(size);
				m.erase(x);
				m.insert(u1);
				m.insert(u2);
			}
		}
print:
		cout << (yes ? "YES\n" : "NO\n");
		s.clear();
		m.clear();
	}
}
