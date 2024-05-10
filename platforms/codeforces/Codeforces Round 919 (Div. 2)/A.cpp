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

ll n, t, minimum, maximum, ans;
vector<ll> notn;
int solve() {
	minimum = LLONG_MAX, maximum = LLONG_MIN, ans = 0;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; ++i) {
		cin >> t >> a[i];
		switch(t) {
			case 1: {
				if (minimum == LLONG_MAX)
					minimum = min(a[i], minimum);
				else
					minimum = max(a[i], minimum);
				break;
							}
			case 2: {
				if (maximum == LLONG_MIN)
					maximum = max(a[i], maximum);
				else 
					maximum = min(a[i], maximum);
				break;
							}
			case 3: {
				notn.push_back(a[i]); break;
							}
		}
	}
	for (auto &i: notn) {
		if ((i <= maximum) && (i >= minimum))
			++ans;
	}
	ans = maximum - minimum + 1 - ans;
	cout << (maximum >= minimum && ans > 0 ? ans : 0) << '\n';
	notn.clear();
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1e9;
	cin >> T;
	#ifdef ONPC
		cout << "__________________________" << '\n';
	#endif
	for (int i = 0; i < T; i++) {
		if (solve()) {
			break;
		}
		#ifdef ONPC
			cout << "__________________________" << '\n';
		#endif
	}
	#ifdef ONPC
		cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC <<
		"second(s)" << '\n';
	#endif
}

