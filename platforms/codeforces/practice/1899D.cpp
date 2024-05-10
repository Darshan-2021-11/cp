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
		u32 n;
		ll ans = 0;
		cin >> n;

		u32 a[n];
		map<u32, u32> count;
		for (u32 i = 0; i < n; ++i) {
			cin >> a[i];
			if (a[i] == 1 || a[i] == 2)
				++count[1];
			else
				++count[a[i]];
		}
		for (auto i: count) {
			ans += ((ll)i.second * (i.second - 1)) >> 1;
		}
		cout << ans << '\n';
	}
	#ifndef ONLINE_JUDGE
		cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
	#endif
}

