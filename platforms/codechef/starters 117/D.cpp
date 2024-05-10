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
using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

//mt19937 rnd(239);
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll a, b, d, c, t, ans;
int solve() {
	cin >> a >> b;
	d = abs(a - b) << 1;
	c = 0;
	for (t = d; t > 0; t >>= 1) {
		while ([](ll u){ return u * u + u; }(c + t) <= d) c += t;
	}
	d >>= 1;
	for (ll i = 0; i < 4; ++i) {
		a = (((c + i) * (c + i + 1)) >> 1);
		if ( (a - d) & 1 )
			continue;
		else if (d <= a) {
			ans = i + c;
			break;
		}
	}
	cout << ans << '\n';
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

