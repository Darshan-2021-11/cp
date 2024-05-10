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
	int n;
	bool less = false;
	ll prefix_sum = 0;
	cin >> n;

	ll a[n];
	vector<int> cursed;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	prefix_sum = a[0];
	for (int i = 1; i < n; ++i) {
		if (a[i] <= prefix_sum) {
			cursed.push_back(a[i]);
			a[i] = -1;
		} else {
			prefix_sum += a[i];
		}
	}
	cout << cursed.size() << '\n';
	for (int i = 0; i < n; ++i) {
		if (a[i] != -1) {
			cout << a[i] << ' ';
		}
	}
	for (int i = 0; i < cursed.size(); ++i) {
		cout << cursed[i] << ' ';
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

