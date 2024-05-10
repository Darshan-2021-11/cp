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

int x, n, t, d, ans;
int solve() {
	cin >> x >> n;
	ans = -1, d = INT_MAX;
	for (int i = 1; i < sqrt(x) + 1; ++i) {
		if (x % i == 0) {
			t = x / i;
			if (t >= n) {
				d = min(d, t);
			}
			t = x / t;
			if (t >= n) {
				d = min(d, t);
			}
		}
	}
	cout << (x / d) << '\n';
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1e9;
	cin >> T;
	#ifndef ONLINE_JUDGE
		cout << "__________________________" << '\n';
	#endif
	for (int i = 0; i < T; i++) {
		if (solve()) {
			break;
		}
		#ifndef ONLINE_JUDGE
			cout << "__________________________" << '\n';
		#endif
	}
	#ifndef ONLINE_JUDGE
		cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC <<
		"second(s)" << '\n';
	#endif
}

