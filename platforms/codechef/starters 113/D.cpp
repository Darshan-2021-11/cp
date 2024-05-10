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

int x, y, t, ans;
int solve() {
	cin >> x >> y;
	if (x - y < 2) {
		ans = 1;
	} else {
		t = x / (y + 1);
		switch (t) {
			case 1:
				ans = 1 + (x - t * (y + 1) > 0);
				break;
			default:
				ans = x - 2 * y;
				break;
		}
	}
	cout << ans << '\n';
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

