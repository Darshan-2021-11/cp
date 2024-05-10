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

int a[1000][1000];

int n = 3, m, odd = 11, even = 10, target, tmptarget;
int solve() {
	bool toogleodd;
	cin >> m;

	if (m == 2) {
		cout << -1 << '\n';
		return 0;
	}
/* Symmetrical answer does not work for even numbered input :(
	for (int i = n; i < m; ++i) {
		int j = 0;
		target = (i + 1) >> 1;
		tmptarget = 0;
		toogleodd = true;

		while (j < i) {
			if (toogleodd) {
				a[j++][i] = odd; odd += 2;
			} else {
				a[j++][i] = even; even += 2;
			}
			if (++tmptarget == target)
				toogleodd = false, tmptarget = 0;
		}

		toogleodd = true;
		tmptarget = 0;
		for (; j < 2 * i + 1; ++j) {
			if (tmptarget == target)
				toogleodd = false;
			if (toogleodd) {
				a[i][j - i] = odd; odd += 2;
			} else {
				a[i][j - i] = even; even += 2;
			}
			if (++tmptarget == target)
				toogleodd = false, tmptarget = 0;
		}
	}
*/
	for (int i = n; i < m; ++i) {
		a[0][i] = odd; odd += 2;
		a[i][0] = odd, odd += 2;
		int j = 1;
		target = pow(i + 1, 2);
		toogleodd = true;
		for (; j < 2 * i; ++j) {
			if (odd > target) {
				toogleodd = false;
			}
			if (j < i) {
				if (toogleodd) {
					a[j][i] = odd; odd += 2;
				} else {
					a[j][i] = even; even += 2;
				}
			} else {
				if (toogleodd) {
					a[i][2 * i - j] = odd; odd += 2;
				} else {
					a[i][2 * i - j] = even; even += 2;
				}
			}
		}
		
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << (a[i][j]) << '\t';
		}
		cout << '\n';
	}
	cout << '\n';
	n = max(n, m);
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

	a[0][0] = 1, a[0][1] = 2, a[0][2] = 4,
	a[1][0] = 6, a[1][1] = 8, a[1][2] = 3,
	a[2][0] = 5, a[2][1] = 7, a[2][2] = 9;

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

