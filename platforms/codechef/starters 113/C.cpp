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
	int n;
	cin >> n;
	int a[n];
	unordered_map<int, int> count;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		++count[a[i]];
	}

	if (count.size() > 1 && n > 4) cout << "YES\n";
	else if (count.size() == 1) cout << "NO\n";
	else if (n == 4 && a[0] + a[1] == a[2] + a[3]) cout << "NO\n";
	else cout << "YES\n";
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

