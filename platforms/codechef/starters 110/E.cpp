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

bool isPrime(int h) {
	if (h < 2) return false;
	else if (h == 2) return true;
	else if (!(h & 1)) return false;

	for (int i = 3; i <= sqrt(h); i += 2) {
		if (!(h % i)) {
			return false;
		}
	}
	return true;
}

int solve() {
	int h, strength = 1, steps = 0;
	cin >> h;

	while (h > 0) {
		++steps;
		if (isPrime(h)) {
			h = 0;
			break;
		}
		h -= strength;
		strength *= 2;
	}
	cout << (h == 0 ? steps : -1) << '\n';
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

