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
	int n, tmp, ai, aip1, i, index = 0, oddcount = 0, evencount = 0;
	cin >> n;

	vector<int> odd, even;
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		if (tmp & 1) {
			++oddcount;
			odd.push_back(tmp);
		} else {
			++evencount;
			even.push_back(tmp);
		}
	}

	if (oddcount & 1) {
		cout << -1 << '\n';
		return 0;
	}

	sort(odd.begin(), odd.end());
	sort(even.begin(), even.end());

	i = 0;
	while(oddcount > 0) {
		ai = (odd[odd.size() - 1 - i] + odd[(odd.size() >> 1) - 1 - i]) >> 1;
		aip1 = (odd[odd.size() - 1 - i] - odd[(odd.size() >> 1) -1 - i]) >> 1;
		a[index] = ai;
		a[index++ + (n >> 1)] = aip1;
		++i, oddcount -= 2;
	}
	i = 0;
	while(evencount > 0) {
		ai = (even[even.size() - 1 - i] + even[(even.size() >> 1) - 1 - i]) >> 1;
		aip1 = (even[even.size() - 1 - i] - even[(even.size() >> 1) - 1 - i]) >> 1;
		a[index] = ai;
		a[index++ + (n >> 1)] = aip1;
		++i, evencount -= 2;
	}
	for (auto i: a) {
		cout << i << ' ';
	}
	cout << '\n';
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

