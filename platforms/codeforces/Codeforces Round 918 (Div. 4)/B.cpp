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

char a[3][3];
bool evaluate;
int solve() {
	evaluate = false;
	for (int i = 0; i < 3; ++i) {
		bool p[3] = { false, false, false };
		for (int j = 0; j < 3; ++j) {
			cin >> a[i][j];
			if (a[i][j] == '?') {
				evaluate = true;
			} else {
				p[a[i][j] - 'A'] = true;
			}
		}
		if (evaluate) {
			for (int k = 0; k < 3; ++k) {
				if (p[k] == false) {
					cout << (char)('A' + k) << '\n';
					break;
				}
			}
		}
	}
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

