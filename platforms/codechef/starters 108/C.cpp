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
	int n, clan = INT_MAX, days = INT_MAX;
	cin >> n;

	int a[n];
	unordered_map <int, vector<int>> present;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		present[a[i]].push_back(i);
	}
	int max_days;
	for (auto it = present.begin(); it != present.end(); ++it) {
		max_days = -1;
		if ((*it).second.size() == 1) {
			max_days = max(n - (*it).second[0] - 1, (*it).second[0]);
		} else {
			max_days = max((*it).second.front(), n - (*it).second.back() - 1);
			for(int j = 0; j < ((*it).second.size() - 1); ++j) {
				int diff = (*it).second[j + 1] - (*it).second[j] - 1;
				max_days = max(max_days, (diff >> 1) + (diff & 1));
			}
		}
		if (max_days < days) {
			days = max_days;
			clan = (*it).first;
		}
		 else if(max_days == days) {
			if ((*it).first < clan)
				clan = (*it).first;
		}
	}

	cout << clan << ' ' << days << '\n';
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
