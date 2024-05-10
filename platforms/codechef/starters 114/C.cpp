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
	int n, score = 0, attain;
	bool found = false;
	cin >> n;
	attain = (n >> 1) + 1;

	char a[n], b[n];
	for (int i = 0; i < n; ++i) b[i] = 'P';
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] == 'R')
			++score;
	}
	if (score >= attain) {
		found = true;
	}
	if (!found) {
		for (int i = n - 1; i > -1; --i) {
			switch(a[i]) {
				case 'P': b[i] = 'S', ++score; break;
				case 'S': b[i] = 'R', ++score; break;
				default: break;
			}
			if (score == attain)
				break;
		}
	}

	for (int i = 0; i < n; ++i) cout << b[i];
	cout << '\n';
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1e9;
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

