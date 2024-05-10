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
	int n, empty = 0, maxempty = INT_MIN, totalempty = 0;
	cin >> n;
	char s[n];

	for(int i = 0; i < n; ++i) {
		cin >> s[i];
		if (s[i] == '.')
			++empty, ++totalempty;
		else {
			maxempty = max(maxempty, empty);
			empty = 0;
		}
	}
	maxempty = max(maxempty, empty);
	cout << (maxempty > 2 ? 2 : totalempty) << '\n';
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

