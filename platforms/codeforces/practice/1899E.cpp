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
		u32 n, i, ans = 0;
		bool isSorted = true;
		cin >> n;
		u32 a[n], minval;

		cin >> a[0];
		minval = a[0];
		for (i = 1; i < n; ++i) {
			cin >> a[i];
			minval = min(minval, a[i]);
			isSorted = isSorted && a[i] >= a[i - 1];
		}
		if (isSorted) {
			cout << ans << '\n';
			continue;
		}
		i = 0, isSorted = true;
		while (a[i] != minval) ++i;
		ans = i;
		for (; i < n - 1; ++i) {
			if (a[i] > a[i + 1])
				isSorted = false;
		}
		if (isSorted) {
			cout << ans << '\n';
		} else {
			cout << -1 << '\n';
		}
	}
	#ifndef ONLINE_JUDGE
		cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
	#endif
}

