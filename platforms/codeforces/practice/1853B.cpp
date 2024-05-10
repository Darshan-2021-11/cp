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

int k, n, tmp, ans;
vector<int> fibonnaci = { 0, 1 };

void addfibonnaci() {
	while (fibonnaci.back() <= 200001) {
		fibonnaci.push_back(fibonnaci[fibonnaci.size() - 1] + fibonnaci[fibonnaci.size() - 2]);
	}
}

int solve() {
	ans = 0, tmp = -1;
	cin >> n >> k;

	if (n == 0) {
		cout << 1 << '\n';
		return 0;
	}
	if (fibonnaci.size() > k) {
		// limit of a is the next fibonnaci after f[k - 1]
		for (int i = 0; i <= n / fibonnaci[k]; ++i) {
			if(!((n - i * fibonnaci[k - 2]) % fibonnaci[k - 1])) {
				tmp = i;
				break;
			}
		}

		if (tmp != -1)
			ans = ((n / fibonnaci[k]) - tmp) / fibonnaci[k - 1] + 1;
	}
	cout << ans << '\n';
	return 0;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	addfibonnaci();
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
