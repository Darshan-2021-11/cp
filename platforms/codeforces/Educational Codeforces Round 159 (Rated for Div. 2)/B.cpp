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

ll n, l, t, p, practical, pts, u;

int solve() {
	cin >> n >> p >> l >> t;

	// completes task and attend college once two weeks
	practical = (n / 7) + (n % 7 != 0);
	pts = ((ll)2 * t) + l;

	if (p > 0) {
	  if ((practical >> 1) > (p / pts)) {
			n -= p / pts + 1;
			p -= (p / pts + 1) * pts;
			practical -= p / pts + 1;
		} else {
			n -= practical >> 1;
			p -= (practical >> 1) * pts;
			practical = practical & 1;
		}
	}
	if ((p > 0) && practical) {
		p -= (pts - t) * practical;
		--n;
	}
	if (p > 0) {
		n -= (p / l) + (p % l != 0);
	}
	cout << n << '\n';
	return 0;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int TET = 1e9;
	cin >> TET;
	for (int i = 1; i <= TET; i++) {
		if (solve()) {
			break;
		}
		#ifdef ONPC
			cout << "__________________________" << "\n";
		#endif
	}
	#ifdef ONPC
		cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC <<
		"second(s)" << "\n";
	#endif
}

