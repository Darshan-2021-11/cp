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
		int n, t, maxv = 0, ans = 0;
		cin >> n;
		vector<int> count(n + 1, 0);
		for (int i = 0; i < n; ++i) {
			cin >> t;
			++count[t];
			maxv = max(maxv, t);
		}
		for (int b = (maxv >> 1) + (maxv & 1); b >= 1; b >>= 1) {
			while (ans + b <= maxv && [&] {
					bool inc = true;
					vector<u32> tmpcnt;
					for (int i = 0; i <= ans + b; ++i) tmpcnt.emplace_back(count[i]);
					sort(tmpcnt.begin(), tmpcnt.end());
					u32 x = 0;
					for (auto &i: tmpcnt) {
						if (!(i > x)) { inc = false; break; }
						if (!x) ++x;
					}
					return inc;
					}()) ans += b;
		}
		cout << (count[0] ? ans + 1 : 0) << '\n';
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

