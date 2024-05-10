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

ll n, m, c1, c2, result;
int solve() {
	cin >> n;
	ll a[n], costf[n], costb[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	costf[0] = costb[n - 1] = 0;
	costf[1] = costb[n - 2] = 1;
	for (int i = 2; i < n; ++i) {
		if (a[i] - a[i - 1] > a[i - 1] - a[i - 2]) {
			costf[i] = costf[i - 1] + a[i] - a[i - 1];
		} else {
			costf[i] = costf[i - 1] + 1;
		}
	}
	for (int i = n - 3; i > -1; --i) {
		if (a[i + 2] - a[i + 1] > a[i + 1] - a[i]) {
			costb[i] = costb[i + 1] + 1;
		} else {
			costb[i] = costb[i + 1] + a[i + 1] - a[i];
		}
	}

	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> c1 >> c2;
		--c1, --c2;
		if (c1 > c2) {
			cout << costb[c2] - costb[c1];
		} else {
			cout << costf[c2] - costf[c1];
		}
		cout << '\n';
	}
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

