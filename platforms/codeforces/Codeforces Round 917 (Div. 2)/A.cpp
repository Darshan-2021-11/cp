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
	int n, negcnt = 0;
	bool zero = false;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] == 0) zero = true;
		else if(a[i] < 0) ++negcnt;
	}

	if (zero || (negcnt & 1)) {
		cout << 0 << '\n';
	} else {
		cout << 1 << '\n' << 1 << ' ' << 0 << '\n';
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1e9;
	cin >> T;
	for (int i = 0; i < T; i++) {
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

