#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

//mt19937 rnd(239);
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), 
	cout.precision(15), cout.setf(ios::fixed);

	u32 T = 1;
	cin >> T;

	while (T--) {
		int n, m, x, dr, c;
		char dir;
		cin >> n >> m >> x;
		vector<set<int>> t(2);
		t[0].insert(x);
		for (int i = 0; i < m; ++i) {
			cin >> dr >> dir;
			bool idx = i & 1;
			for (auto &j: t[idx]) {
				switch(dir) {
					case '0':
						c = (j + dr) % n;
						t[!idx].insert(c);
						break;
					case '1':
						c = (j + n - dr) % n;
						t[!idx].insert(c);
						break;
					case '?':
						c = (j + dr) % n;
						t[!idx].insert(c);
						c = (j + n - dr) % n;
						t[!idx].insert(c);
						break;
				}
			}
			t[idx].clear();
		}
		bool idx = m & 1, zero = t[idx].find(0) != t[idx].end();
		cout << t[idx].size() << '\n';
		for (auto &i: t[idx]) if (i != 0) cout << i << ' ';
		if (zero) cout << n;
		cout << '\n';
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

