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
	int n, forward_min = INT_MAX;
	cin >> n;
	int a[n];
	ll operations = 0;
	bool isAscending = true;

	cin >> a[0];
	for (int i = 1; i < n; ++i) {
		cin >> a[i];
		if (a[i] < a[i - 1])
			isAscending = false;
		if (forward_min > a[i])
			forward_min = a[i];
	}

	if (isAscending) {
		cout << 0 << '\n';
		return 0;
	}

	for (int j = n - 1; j > -1; --j) {
		
	}

	cout << operations << '\n';

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

