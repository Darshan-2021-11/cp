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

int n, k, indexpbds, value;
int solve() {
	indexed_set a;
	indexpbds = 0;
	cin >> n >> k;

	for (int i = 1; i <= n; ++i) {
		a.insert(i);
	}
	while (n) {
		indexpbds = (indexpbds + k % n) % n;
		value = *a.find_by_order(indexpbds);
		cout << value << ' ';
		a.erase(value);
		--n;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// cin >> T;
	#ifdef ONPC
		cout << "__________________________" << '\n';
	#endif
	solve();
	#ifdef ONPC
		cout << "__________________________" << '\n';
	#endif
	#ifdef ONPC
		cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC <<
		"second(s)" << '\n';
	#endif
}

