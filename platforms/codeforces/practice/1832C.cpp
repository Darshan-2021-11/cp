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
	int n, ans;
	bool ne = false, increasing, curr;
	cin >> n;
	ans = n;
	ll a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		if (ne) {
			curr = a[i + 1] > a[i];
			if (curr == increasing) {
				--ans;
			} else if (a[i + 1] == a[i]) {
				--ans;
			} else {
				increasing = curr;
			}
		} else {
			if(a[i + 1] == a[i]) {
				--ans;
			} else {
				ne = true;
				increasing = a[i + 1] > a[i];
			}
		}
	}
	if (ans == 2) {
		if (a[0] - a[n - 1] == 0)
			ans = 1;
	}
	cout << ans << '\n';
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

