#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using u32 = unsigned int;
using ll = long long;
using ld = long double;
using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

//mt19937 rnd(239);
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(15);

	u32 T = 1;
	cin >> T;

	while (T--) {
		u32 n, q, currmax = 1, maximum = 1;
		cin >> n >> q;
		char p, t;
		cin >> p;
		for (u32 i = 1; i < n; ++i) {
			cin >> t;
			if (t == p) {
				++currmax;
			} else {
				maximum = max(currmax, maximum);
				currmax = 1;
			}
			p = t;
		}
		maximum = max(currmax, maximum);
		cout << maximum << ' ';
		for (u32 i = 0; i < q; ++i) {
			cin >> t;
			if (t == p) {
				++currmax;
			} else {
				currmax = 1;
			}
			p = t;
			maximum = max(currmax, maximum);
			cout << maximum << ' ';
		}
		cout << '\n';
	}
	#ifndef ONLINE_JUDGE
		cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
	#endif
}

