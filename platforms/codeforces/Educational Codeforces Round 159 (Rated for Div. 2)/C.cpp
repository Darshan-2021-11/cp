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

ll operations;
int n, diff, tmp;
bool found;

int solve() {
	// tmp stores the max element
	operations = 0, tmp = INT_MIN, found = false;
	cin >> n;
	ll a[n + 2];

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << 1 << '\n';
		return 0;
	}
	sort(a, a + n);
	tmp = a[n - 1];

	diff = a[1] - a[0];
	for (int i = 1; i < n - 1; ++i) {
		diff = gcd(a[i + 1] - a[i], diff);
	}
	for (int i = n - 2; i > -1; --i) {
		if (a[i + 1] - diff != a[i]) {
			a[n] = a[i + 1] - diff;
			found = true;
			break;
		}
	}
	if (!found) {
		a[n] = a[0] - diff;
	}
	for (int i = 0; i < n + 1; ++i) {
		operations += (a[n - 1] - a[i]) / diff;
	}

	// if we could add or subtract `x` #MISINTERPRETQUESTION
// average = 0;
//for (int i = 0; i < n; ++i) {
//	average += a[i];
//}
//average = average / n;
//for (int i = 0; i < n; ++i) {
//	if ((average - a[i]) % diff) {
//		tmp = (average - a[i]) % diff;
//		average = min(tmp, diff - tmp);
//		break;
//	}
//}
//	// Binary search from the middle neighbouring to average and traverse left
//	// and right, if an element is not present with difference of diff, make it
//	// the added number
//
//for (int i = 0; i < n; ++i) {
//	operations += abs(a[i] - average) / diff;
//}
	cout << operations << '\n';
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

