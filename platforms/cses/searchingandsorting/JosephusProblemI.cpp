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

int n, dn, i, ti, oti;

int solve() {
	cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	dn = n, i = 1;
	int a[n], b[(n >> 1) + (n & 1)];
	int *arr[2] = { a, b };
	iota(a, a + n, 1);

	while (dn) {
		cout << (arr[0][i]) << ' ';
		--dn;
		i += 2;
		if (i < n)
			continue;

		swap(arr[0], arr[1]);
		i = 1, ti = 0, oti = 0;
		if (n & 1) {
			arr[0][ti++] = arr[1][n - 1];
		}

		while (ti < dn) {
			arr[0][ti++] = arr[1][oti];
			oti += 2;
		}

		n = dn;
		if (n == 1)
			i = 0;
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	#ifdef ONPC
		cout << "__________________________" << '\n';
	#endif
		solve();
	#ifdef ONPC
		cout << "__________________________" << '\n';
	#endif
	#ifdef ONPC
		cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC <<
		"second(s)" << '\n';
	#endif
}

