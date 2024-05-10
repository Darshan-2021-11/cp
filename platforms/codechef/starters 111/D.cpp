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

int n;
int solve() {
	cin >> n;
	int a[n], b[n];
	vector<int> c(n);
	unordered_map<int, int> c1, c2;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		c[i] = a[i];
		++c1[a[i]];
	}
	sort(c.begin(), c.end());
	for (int i = 0; i < n; ++i) {
		if (c2[a[i]] < 1) {
			b[i] = a[i];
			++c2[a[i]];
		} else {
			while(c1[c.back()] == c2[c.back()]) {
				c.pop_back();
			}
			b[i] = c.back();
			++c2[a[i]];
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << b[i] << ' ';
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

