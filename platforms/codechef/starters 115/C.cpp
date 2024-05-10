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

int n, x;
int solve() {
	cin >> n >> x;
	if (n < 3) {
		if (x)
			cout << -1;
		else
			for (int i = 1; i <= n; ++i) cout << i << ' ';
		cout << '\n';
		return 0;
	}
	if (x > n - 2) {
		cout << -1 << '\n';
		return 0;
	}
	if ((n & 1) == (x & 1)) {
		for (int i = n - ((n - x) >> 1) + 1; i <= n; ++i) cout << i << ' ';
		for (int i = 1; i <= n - ((n - x) >> 1); ++i) cout << i << ' ';
		cout << '\n';
	} else {
		cout << 1 << ' ';
		for (int i = n - ((n - x) >> 1) + 1; i <= n; ++i) cout << i << ' ';
		for (int i = 2; i <= n - ((n - x) >> 1); ++i) cout << i << ' ';
		cout << '\n';
	}
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

