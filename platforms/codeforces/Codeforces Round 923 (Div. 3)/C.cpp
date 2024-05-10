#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;
using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

//mt19937 rnd(239);
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(15);

	u32 T = 1, n, m, k, t, ac, bc;
	bool possible;
	cin >> T;

	while (T--) {
		ac = bc = 0;
		possible = true;
		cin >> n >> m >> k;
		bool found[k], foundi[k];
		memset(found, 0, k);
		memset(foundi, 0, k);
		for (u32 i = 0; i < n; ++i) {
			cin >> t;
			if (--t < k && !foundi[t]) found[t] = foundi[t] = true, ++ac;
		}
		if (ac < (k >> 1)) possible = false;
		memset(foundi, 0, k);
		for (u32 i = 0; i < m; ++i) {
			cin >> t;
			if (--t < k && !foundi[t]) found[t] = foundi[t] = true, ++bc;
		}
		if (bc < (k >> 1)) possible = false;
		if (possible) {
			for (t = 0; t < k; ++t) {
				if (!found[t]) {
					possible = false;
					break;
				}
			}
		}

		if (possible) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	#ifndef ONLINE_JUDGE
		cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
	#endif
}

