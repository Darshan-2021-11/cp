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

int counts[3], oppabs, diff;
bool possible[3];
int solve() {
	for (int i = 0; i < 3; ++i) {
		cin >> counts[i];
	}

	oppabs = min(counts[1], counts[2]);
	diff = (max(counts[1], counts[2]) - oppabs);
	possible[0] = !(diff & 1);
	oppabs = min(counts[0], counts[2]);
	diff = (max(counts[0], counts[2]) - oppabs);
	possible[1] =  !(diff & 1);
	oppabs = min(counts[0], counts[1]);
	diff = (max(counts[0], counts[1]) - oppabs);
	possible[2] = !(diff & 1);

	for (int i = 0; i < 3; ++i) {
		cout << possible[i] << ' ';
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

