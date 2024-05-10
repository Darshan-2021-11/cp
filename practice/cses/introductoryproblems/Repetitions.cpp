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

char c, p;
int tans, ans;

int solve() {
	tans = ans = 1;
	cin.get(p);
	while (cin.get(c)) {
		if (c == p) {
			++tans;
		} else {
			ans = max(tans, ans); 
			tans = 1;
			p = c;
		}
	}
	cout << ans << '\n';
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	#ifndef ONLINE_JUDGE
		cout << "__________________________" << '\n';
	#endif
	solve();
	#ifndef ONLINE_JUDGE
		cout << "__________________________" << '\n';
	#endif
	#ifndef ONLINE_JUDGE
		cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC <<
		"second(s)" << '\n';
	#endif
}

