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

	while (T--) {
		u32 n, x;
		cin >> n >> x;
		vector<pair<u32, u32>> val(n);
		for (u32 i = 0; i < n; ++i) {
			cin >> val[i].first;
			val[i].second = i;
		}
		sort(val.begin(), val.end());

		for (u32 i = 0; i < n - 2 && val[i].first <= x / 3; ++i) {
			u32 j = i + 1, k = n - 1, req = x - val[i].first, t;
			while (j < k && (t = val[j].first + val[k].first) != req) {
				if (t < req) ++j;
				else --k;
			}
			if (t == req) {
				cout << val[i].second + 1 << ' ' << val[j].second + 1 << ' ' << val[k].second + 1;
				return 0;
			}
		}
		cout << "IMPOSSIBLE";
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

