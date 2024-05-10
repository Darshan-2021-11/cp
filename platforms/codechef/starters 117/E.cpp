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

ll m, n, u, mir, mar, ans;
const ll MOD = 998'244'353;
int solve() {
	ans = 0;
	cin >> m >> n;
	if (n > m) swap(m, n);
	u = m >> 1;
	mir = max(n - u, 1LL); 
	mar = n - mir + 1;
	ans = ( (mar) * (mar + 1) - (mir - 1) * (mir) ) >> 1;
	ans %= MOD;
	if (m & 1) {
		ans = (u + 1) * ans;
	} else {
		ans = (2 * u + 1) * ans;
	}
	ans %= MOD;
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
