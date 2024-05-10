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

??
int n, currindex;
ll a[(int)1e5], maxval, tmp1, tmp2;
int solve() {
	cin >> n;
	currindex = 1;

	cin >> a[0];
	maxval = currindex * a[0];

	for (int i = 1; i < n; ++i) {
		cin >> a[i];
		tmp1 = maxval + (currindex + 1) * a[i];
		tmp2 = maxval + currindex * a[i];

		if (tmp1 > tmp2)
			maxval = tmp1, cout << currindex << ' ' << a[i] << ',', ++currindex;
		else
			maxval = tmp2;
	}

	cout << currindex << ' ' << maxval << '\n';

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

