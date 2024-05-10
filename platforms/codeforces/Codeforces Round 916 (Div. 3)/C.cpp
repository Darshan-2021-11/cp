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
	int n, k;
	cin >> n >> k;
	ll a[n], b[n], mb = 0;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	ll pa = 0, ans = 0;
	for (int i = 0; i < min(n, k); ++i) {
		pa += a[i];
		mb = max(b[i], mb);
		ans = max(pa + mb * (k - i - 1), ans);
	}
	cout << ans << '\n';

/*
	ll prefix[n], bm[n];
	prefix[0] = a[0];
	for (int i = 1; i < n; ++i) {
		prefix[i] = prefix[i - 1] + a[i];
	}
	bm[0] = b[0];
	for (int i = 1; i < n; ++i) {
		bm[i] = max(bm[i - 1], b[i]);
	}

	ll maxVal = a[0] + b[0] * (k - 1);
	for (int i = 1; i < min(n, k); ++i) {
		maxVal = max(maxVal, prefix[i] + bm[i] * (k - i - 1));
	}
	cout << maxVal << '\n';
*/
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

