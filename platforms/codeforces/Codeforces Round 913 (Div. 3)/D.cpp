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
	int n;
	cin >> n;

	int l[n + 1], r[n + 1];
	l[0] = 0, r[0] = 0;
	int kmin, kmax, tkmin, tkmax, tmp;
	for (int i = 1; i < n + 1; ++i) {
		cin >> l[i] >> r[i];
	}
	kmin = l[1], kmax = r[1];
	for (int i = 2; i < n + 1; ++i) {
		tmp = l[i] - l[i - 2];
		tkmin = (tmp >> 1) + (tmp & 1);
		tmp = r[i] - r[i - 2];
		tkmax = (tmp >> 1) - (tmp & 1);

		kmin = max(kmin, tkmin);
		kmax = min(kmax, tkmax);
	}
	cout << kmin << '\n';
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

