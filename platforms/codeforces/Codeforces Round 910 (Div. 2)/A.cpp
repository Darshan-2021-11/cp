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
	int n, k, i, countb = 0, tmpcount = 0;
	cin >> n >> k;

	char a[n];
	for (i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] == 'B')
			++countb;
	}
	if (countb == k) {
		cout << 0 << '\n';
	} else if (countb > k) {
		for (i = 0; i < n; ++i) {
			if (a[i] == 'B') {
				++tmpcount;
				if (tmpcount == countb - k)
					break;
			}
		}
		cout << 1 << '\n' << ++i << ' ' << 'A' << '\n';
	} else {
		for (i = 0; i < n; ++i) {
			if (a[i] == 'A') {
				++tmpcount;
				if (tmpcount == k - countb)
					break;
			}
		}
		cout << 1 << '\n' << ++i << ' ' << 'B' << '\n';
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

