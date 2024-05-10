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
	int n, count0 = 0;
	cin >> n;
	char a[n];
	bool possible = false;
	cin >> a[0];
	if (a[0] == '0')
		++count0;
	for (int i = 1; i < n; ++i) {
		cin >> a[i];
		if (a[i] == '0')
			++count0;

		if (a[i] != a[i - 1]) {
			possible = true;
		}
	}
	if (possible || (count0 > (n >> 1)))
		cout << "YES\n";
	else
		cout << "NO\n";
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

