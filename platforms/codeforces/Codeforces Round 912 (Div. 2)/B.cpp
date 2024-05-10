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
	int n, ansi;
	bool exist = true;
	cin >> n;

	int a[n * n], b[n];

	for (int i = 0; i < n * n; ++i) {
		cin >> a[i];
	}

	if (n == 1) {
		cout << "YES\n0\n";
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		b[i] = (1 << 30) - 1;
		for (int j = 0; j < n; ++j) {
			if (j != i)
				b[i] &= a[i * n + j];
		}
	}
	auto found = [] (const int a[], const int b[], const int &n) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (j != i) {
					if (a[i * n + j] != (b[i] | b[j])) {
						return false;
					}
				}
			}
		}
		return true;
	};

	if (found(a, b, n)) {
		cout << "YES\n";
		for (int i = 0; i < n; ++i) {
			cout << b[i] << ' ';
		}
		cout << '\n';
	} else {
		cout << "NO\n";
	}
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

