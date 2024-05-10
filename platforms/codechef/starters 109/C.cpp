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
	int n, tmp, allxor, minxor;
	cin >> n;

	int a[n];
	cin >> a[0];
	allxor = a[0];

	if (n == 1) {
		cout << tmp << '\n';
		return 0;
	}

	for (int i = 1; i < n; ++i) {
		cin >> a[i];
		allxor = allxor ^ a[i];
	}

	minxor = allxor;
	for (int i = 0; i < n; ++i) {
		tmp = allxor ^ a[i];
		minxor = min(tmp, minxor);
	}

	cout << minxor << '\n';
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

