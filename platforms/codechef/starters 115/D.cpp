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

int n, tmp, ans;
int solve() {
	tmp = 0;
	cin >> n;
	ans = n;
	int a[n];
	cin >> a[0];
	if (n == 1) {
		cout << 1 << '\n';
		return 0;
	}
	map<int, int> limin;
	for (int i = 1; i < n; ++i) {
		cin >> a[i];
		if (limin.size() == 0) {
			if (a[i - 1] <= a[i]) {
				++limin[a[i - 1]];
				if (a[i - 1] == a[i])
					++limin[a[i - 1]];
			}
		} else {
			if (a[i] < (*limin.begin()).first) {
				++limin[a[i]];
			} else if (a[i] == (*limin.begin()).first) {
				++limin[a[i]];
			}
		}
	}
	for (auto i: limin) {
		tmp += i.second;
		ans = min(ans, n - tmp + i.first);
	}
	cout << ans << '\n';
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

