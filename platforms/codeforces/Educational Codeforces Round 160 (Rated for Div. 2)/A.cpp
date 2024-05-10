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
	string s;
	int n, a, b, t;
	bool found = false;
	cin >> s;
	n = atoi(s.c_str());
	for (int i = 1; i < s.size(); ++i) {
		t = pow(10, i);
		a = n / t;
		b = n % t;
		if((a < b) && (to_string(a).size() + to_string(b).size() == s.size())) {
			found = true;
			break;
		}
	}
	if (found) {
		cout << a << ' ' << b;
	}
	else {
		cout << -1;
	}
	cout << '\n';
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

