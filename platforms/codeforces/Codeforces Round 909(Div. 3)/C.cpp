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
	long n, prev_parity, curr_parity, tmp;
	cin >> n;

	long a[n], sum = 0;

	for (long i = 0; i < n; ++i) {
		cin >> a[i];
	}

	if (n == 1) {
		cout << a[0] << '\n';
		return 0;
	}

	vector<long> v;
	sum = a[0];
	v.push_back(a[0]);
	for (long i = 1; i < n; ++i) {
		if (sum + a[i] < a[i]) {
			sum = a[i];
			v.push_back(a[i]);
		} else if((a[i] & 1) != (a[i - 1] & 1)) {
			sum = sum + a[i];
			v.push_back(sum);
		} else {
			v.push_back(a[i]);
			sum = a[i];
		};
	}

	for (long i = 0; i < v.size(); ++i) {
		sum = max(sum, v[i]);
	}
	cout << sum << '\n';
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
