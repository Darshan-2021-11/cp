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

int n, minsteps, l1, l2, l3, l4;
char tmp;

int solve() {
	cin >> n;
	char a[n * n];
	minsteps = 0;
	for (int i = 0; i < n * n; ++i)
		cin >> a[i];

	for (int i = 0; i < (n >> 1); ++i) {
		for (int j = 0; j < (n >> 1); ++j) {
			l1 = i * n + j, l2 = (n - j - 1) * n + i, l3 = (n - i - 1) * n + (n - j - 1), l4 = j * n + (n - i - 1);
			tmp = max({ a[l1], a[l2], a[l3], a[l4] });
			minsteps += 4 * tmp - a[l1] - a[l2] - a[l3] - a[l4];
		}
	}

	cout << minsteps << '\n';
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

