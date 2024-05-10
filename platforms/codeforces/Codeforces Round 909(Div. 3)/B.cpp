
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
	ll n;
	ll ans = -1;
	cin >> n;

	ll a[n];
	for (ll i = 0; i < n; ++i) {
		cin >> a[i];
	}

	if (n == 1) {
		cout << 0 << '\n';
		return 0;
	}

	for (ll i = 1; i < n; ++i) {
		ll max_elm = LLONG_MIN, min_elm = LLONG_MAX;
		if (!(n % i)) {
			ll tmp = n / i, index = 0;
			ll b[tmp] { 0 };

			for (ll j = 0; j < tmp; ++j) {
				for (ll k = 0; k < i; ++k) {
					b[j] += a[index++];
				}
				max_elm = max(max_elm, b[j]);
				min_elm = min(min_elm, b[j]);
			}
			ans = max(max_elm - min_elm, ans);
		}
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
