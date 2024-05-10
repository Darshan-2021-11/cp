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
	int n, tmp;
	ll teleportations = 0;
	cin >> n;

	/* 1st approach : fastest */
	stack<int> stack;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		if (stack.empty())
			teleportations += tmp;
		else if (stack.top() < tmp) {
			teleportations += tmp - stack.top();
		}
		while (!stack.empty() && (stack.top() >= tmp)) {
			stack.pop();
		}
		stack.push(tmp);
	}

	/* 2nd approach */
	/*
	int tmp2;
	cin >> tmp;
	teleportations += tmp;
	for (int i = 1; i < n; ++i) {
		cin >> tmp2;
		if (tmp2 > tmp) {
			teleportations += tmp2 - tmp;
		}
		tmp = tmp2;
	}
	*/

	cout << teleportations - 1 << '\n';
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

