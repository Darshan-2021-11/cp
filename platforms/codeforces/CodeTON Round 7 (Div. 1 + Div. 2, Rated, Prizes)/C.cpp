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
	int n, x, tmp, amoreb = 0;
	cin >> n >> x;
	vector<ll> a, b;

	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		a.push_back(tmp);
	}
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		b.push_back(tmp);
	}

	int aindex[n];
	iota(aindex, aindex + n, 0);
	sort(aindex, aindex + n, [&](ll i, ll j) { return a[i] < a[j]; });
	sort(b.begin(), b.end());

	for (int i = 0; i < n; ++i) {
		if (a[aindex[i]] > b[i])
			++amoreb;
	}

	for (int i = 0; i < n; ++i) {
		cout << a[aindex[i]] << ' ';
	}
	cout << '\n';
	a.clear();
	b.clear();

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

