#ifdef ONPC
	#define _GLIBCXX_DEBUG
#endif
// #include <bits/stdc++.h>
#include "bits/stdc++.h"
#define sz(a) ((int)((a).size()))
#define char unsigned char

using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

ll t, v, tmp;
size_t m, i;
int solve() {
	unordered_map<ll, ll> count;
	cin >> m;
	for (i = 0; i < m; ++i) {
		cin >> t >> v;
		if (t == 1) {
			++count[v];
		} else {
			bool found = false;
			for (ll j = 29; j > -1; --j) {
				tmp = v / (1 << j);
				if (tmp && count[j]) {
					v -= (1 << j) * min(tmp, count[j]);
				}
				if (v == 0) {
					cout << "YES";
					found = true;
					break;
				}
			}
			if (!found) {
				cout << "NO";
			}
			cout << '\n';
		}
	}
	return 0;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
		#ifdef ONPC
			cout << "__________________________" << "\n";
		#endif
	#ifdef ONPC
		cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC <<
		"second(s)" << "\n";
	#endif
}

