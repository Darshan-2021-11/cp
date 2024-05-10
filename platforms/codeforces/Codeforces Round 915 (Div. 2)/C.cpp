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
	int n, tmp = 0;
	char c;
	bool possible = true;
	cin >> n;

	char a[n];
	vector<int> pos;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] < a[i - 1]) { possible = false; }
		while (!pos.empty() && (a[i] > a[pos.back()]))
			pos.pop_back();
		pos.push_back(i);
	}
	// if sorted, print 0
	if (possible) {
		cout << 0 << '\n';
		return 0;
	}
	possible = true;
	for (int i = 1; i < pos.size(); ++i) {
		if (a[pos.at(i)] == a[pos.at(i - 1)])
			++tmp;
		else break;
	}
	for (int i = 0; i < (pos.size() >> 1); ++i) {
		c = a[pos.at(i)];
		a[pos.at(i)] = a[pos.at(pos.size() - 1 - i)];
		a[pos.at(pos.size() - 1 - i)] = c;
	}
	for (int i = 1; i < n; ++i) {
		if (a[i] < a[i - 1]) {
			possible = false;
			break;
		}
	}
	if (possible)
		cout << pos.size() - tmp - 1 << '\n';
	else
		cout << -1 << '\n';

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

