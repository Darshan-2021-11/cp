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

int n, x, y, t;
bool xu, yu;
int solve() {
	cin >> n;
	int quad[4] { 0 };
	for (u32 i = 0; i < n; ++i) {
		xu = false, yu = false;
		cin >> x >> y;
		if (x > 0) xu = true;
		if (y > 0) yu = true;
		++quad[2 * yu + xu];
	}
	
		cout << "YES\n";
	} else {
		cout << "NO\n";
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

