#ifdef ONPC
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
// 1. Instead of less<int>, we can also do greater<T>, less_equal<T>,
// greater_equal<T> or any other custom function to compare
// 2. Two additional functions apart from all of that from the set is:
//	a) find_by_order(n), finds `n`th element (iterator)
//	b) order_of_key(n), finds elements smaller than `n` (value)
using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

//mt19937 rnd(239);
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int solve() {
	int arr[]={1,2,0,0,0};
	int n = sizeof(arr) / sizeof(arr[0]), i = 0, ans = 0, t, tmprange, maxrange;
	--n;
	if (n == 0) return ans;
	else if (arr[0] >= n) return ++ans;

	maxrange = i + arr[i], ++i;
	while (i < n) {
		tmprange = maxrange;

		for (; i <= tmprange; ++i) {
			t = i + arr[i];
			if (t >= n) { i = n; break; }
			else if (t > maxrange) { maxrange = t; }
			else if ((arr[i] == 0) && (maxrange == i)) { ans = n; break; }
		}
		++ans;
		if (ans >= n) { ans = -1; break; }
	}
	return ++ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
#ifdef ONPC
	cout << "__________________________" << '\n';
#endif
		cout << solve();
		#ifdef ONPC
			cout << "__________________________" << '\n';
		cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC <<
		"second(s)" << '\n';
	#endif
}

