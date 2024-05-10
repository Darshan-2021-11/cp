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
	u32 n, k, d, minnd, maxs = 0;
	cin >> n >> k >> d;

	minnd = min(n * 2, d);

	int a[n], b[n], v[k];
	for (u32 i = 0; i < n; ++i) {
		cin >> a[i];
		b[i] = (i + 1) - a[i];
	}
	for (u32 i = 0; i < k; ++i) cin >> v[i];

	for (u32 i = 0; i < minnd; ++i) {
		u32 curr = 0;

		for (u32 j = 0; j < n; ++j) {
			if (b[j] == 0) ++curr;
		}
		maxs = max(maxs, ((d - i - 1) >> 1) + curr);

		for (u32 j = 0; j < v[i % k]; ++j) {
			--b[j];
		}
	}

	cout << maxs << '\n';
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

