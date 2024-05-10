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
	int count1, count0 = 0, ans;
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '0')
			++count0;
	}
	if (count0 == s.size() || count0 == 0) {
		cout << s.size() << '\n';
		return 0;
	}
	count1 = s.size() - count0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '0')
			--count1;
		else
			--count0;

		if (!count0) {
			while ((++i < s.size()) && (s[i] == '0') && count1)
				--count1;
			ans = s.size() - i;
			break;
		}
		else if (!count1) {
			while ((++i < s.size()) && (s[i] == '1') && count0)
				--count0;
			ans = s.size() - i;
			break;
		}
	}
	cout << (s.size() == 1 ? 1 : ans) << '\n';
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

