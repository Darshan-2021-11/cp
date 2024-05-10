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

int dfs(int lr[], char a[], int id) {
	--id;
	bool left  = lr[2 * id] != 0;
	bool right = lr[2 * id + 1] != 0;
	if (!left && !right) { return 0; }

	int minChange = INT_MAX;

	if (left) {
		minChange = min(dfs(lr, a, lr[2 * id]) + (a[id] != 'L'), minChange);
	}
	if (right) {
		minChange = min(dfs(lr, a, lr[2 * id + 1]) + (a[id] != 'R'), minChange);
	}
	return minChange;
}

int solve() {
	int n;
	cin >> n;

	int lr[2 * n];
	char a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < 2 * n; i += 2) {
		cin >> lr[i] >> lr[i + 1];
	}

	// root node has id 1
	int ans = dfs(lr, a, 1);
	
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

