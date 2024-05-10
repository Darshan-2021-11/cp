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

bool isVowel(char c) {
	switch(c) {
		case 'a':
		case 'e':
			return true;
		default:
			return false;
	}
}

int solve() {
	int n, lastsyllable = 0, tmp = 0;
	cin >> n;
	char a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (tmp == 3) {
			if (isVowel(a[i])) {
				for (int j = 0; j < 2; ++j) {
					cout << a[lastsyllable++];
				}
				cout << '.';
			} else {
				for (int j = 0; j < 3; ++j) {
					cout << a[lastsyllable++];
				}
				cout << '.';
			}
			tmp = i - lastsyllable;
		}
		++tmp;
	}
	for (;lastsyllable < n;) {
		cout << a[lastsyllable++];
	}
	cout << '\n';
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1e9;
	cin >> T;
	#ifdef ONPC
		cout << "__________________________" << '\n';
	#endif
	for (int i = 0; i < T; i++) {
		if (solve()) {
			break;
		}
		#ifdef ONPC
			cout << "__________________________" << '\n';
		#endif
	}
	#ifdef ONPC
		cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC <<
		"second(s)" << '\n';
	#endif
}

