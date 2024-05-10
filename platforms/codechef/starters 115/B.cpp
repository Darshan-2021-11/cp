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

int n, tmp;
bool possible;
int solve() {
	possible = true;
	cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];

	sort(a, a + n, greater<int>());
	sort(b, b + n);

	tmp = a[0] + b[0];
	for (int i = 1; i < n; ++i) {
		if (a[i] + b[i] != tmp) {
			possible = false;
			break;
		}
	}
	if (possible) {
		for (int i = 0; i < n; ++i) cout << a[i] << ' ';
		cout << '\n';
		for (int i = 0; i < n; ++i) cout << b[i] << ' ';
		cout << '\n';
	} else {
		cout << -1 << '\n';
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

