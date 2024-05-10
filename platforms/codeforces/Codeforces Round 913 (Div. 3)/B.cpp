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
	string s;
	cin >> s;
	vector<int>a, c;
	for (int i = 0; i < s.size(); ++i) {
		if((s[i] >= 'a') && (s[i] <= 'z') && (s[i] != 'b'))
			a.push_back(i);
		else if((s[i] >= 'A') && (s[i] <= 'Z') && (s[i] != 'B'))
			c.push_back(i);
		else if(s[i] == 'b') {
			if (a.size()) {
				s[a.back()] = ' ';
				a.pop_back();
			}
		} else if(s[i] == 'B') {
			if (c.size()) {
				s[c.back()] = ' ';
				c.pop_back();
			}
		}
	}

	for (int i = 0; i < s.size(); ++i) {
		switch(s[i]) {
			case 'b':
			case 'B':
			case ' ':
				continue;
				break;
			default:
				cout << s[i];
				break;
		}
	}
	cout << '\n';
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

