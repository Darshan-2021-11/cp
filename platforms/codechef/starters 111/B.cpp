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

bool possible;
char a[8];

int solve() {
	possible = true;
	auto vowel =
	[&] (char a) {
		switch (a) {
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				return true;
			default:
				return false;
		}
	};
	for (int i = 0; i < 8; ++i) {
		cin >> a[i];
		switch (i) {
			case 1:
			case 3:
			case 5:
				possible &= vowel(a[i]);
				break;
			default:
				possible &= !(vowel(a[i]));
				break;
		}
	}
	if (possible) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
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

