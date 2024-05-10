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
	int n, ans;
	cin >> n;

	ans = n;
	char a[n];
	int count[26] { 0 };

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		++count[a[i] - 'a'];
	}

	stack<char> s;

	for (int i = 0; i < n; ++i) {
		if (s.empty()) {
			s.push(a[i]);
		}
		else if (count[s.top() == count[a[i]]]) {
			s.push(a[i]);
		}	else if (count[a[i]] > count[s.top()]){
			--count[a[i]]; --count[s.top()];
			s.pop();
			ans -= 2;
		}
	}
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

