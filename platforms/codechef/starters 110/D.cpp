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

int solve() {
	int a, b, ao, bo, x = 0, req;
	cin >> ao >> bo;
	a = ao, b = bo;
	if (a % b == 0) {
		cout << 0 << '\n';
		return 0;
	} else {
		while (b > 1) {
			a++, b--, x++;
			if (!(a % b)) {
				req = x;
				break;
			}
		}
		a = ao, b = bo, x = 0;
		while (a > 1) {
			a--, b++, x++;
			if (!(a % b)) {
				req = min(x, req);
				break;
			}
		}
		cout << req << '\n';
	}
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

