#ifdef ONPC
	#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>

using namespace std;
using u32 = unsigned int;
using ll = long long;
using ld = long double;

//mt19937 rnd(239);
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int solve() {
	int n, t;
	bool possible = false;
	cin >> n;
	ll prefix = 0;
	set<ll> diff;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		if (i & 1) {
			t = -t;
		}
		prefix += t;
		if (prefix == 0 || diff.find(prefix) != diff.end()) {
			possible = true;
		}
		diff.insert(prefix);
	}
	if (possible)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1e9;
	cin >> T;
	#ifdef ONPC
		cout << "__________________________" << '\n';
	#endif
	for (int i = 0; i < T; i++) {
		if (solve()) {
			break;
		}
		#ifdef ONPC
			cout << "__________________________" << '\n';
		#endif
	}
	#ifdef ONPC
		cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC <<
		"second(s)" << '\n';
	#endif
}

