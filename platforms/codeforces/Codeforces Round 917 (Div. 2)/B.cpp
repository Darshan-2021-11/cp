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
	int n, unique = 1;
	cin >> n;
	char a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];

	ll possiblities = 1;
	unordered_map<char, bool> present;
	present[a[0]] = true;
	for (int i = 1; i < n; ++i) {
		present[a[i]] = true;
		possiblities += present.size();
	}
	cout << possiblities << '\n';
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
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

