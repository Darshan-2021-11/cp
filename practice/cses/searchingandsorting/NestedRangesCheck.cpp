#ifndef ONPC
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;
using u32 = unsigned int;
using ll = long long;
using ld = long double;
// 1. Instead of less<int>, we can also do greater<T>, less_equal<T>,
// greater_equal<T> or any other custom function to compare
// 2. Two additional functions apart from all of that from the set is:
//	a) find_by_order(n), finds `n`th element (iterator)
//	b) order_of_key(n), finds elements smaller than `n` (value)

//mt19937 rnd(239);
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int n, currmax;
int solve() {
	currmax = 0;
	cin >> n;
	pair<pair<int, int>, pair<int, pair<bool, bool>>> a[n];
	map<int, int> index;
	map<int, int>::iterator it;

	for (int i = 0; i < n; ++i) {
		cin >> a[i].first.first >> a[i].first.second;
		a[i].second.first = i;
		a[i].second.second.first = a[i].second.second.second = false;
	}

	sort(a, a + n, [](pair<pair<int, int>, pair<int, pair<bool, bool>>> &b, pair<pair<int, int>, pair<int, pair<bool, bool>>> &c) {
			if (b.first.first != c.first.first)
				return b.first.first < c.first.first;
			else
				return b.first.second > c.first.second;
		});

	for (int i = 0; i < n; ++i) {
		if (a[i].first.second <= currmax) {
			a[i].second.second.second = true;

			it = index.lower_bound(a[i].first.second);
			while (it != index.end()) {
				a[(*it).second].second.second.first = true;
				it = index.erase(it);
			}
		} else
			currmax = a[i].first.second;
		index[a[i].first.second] = i;
	}

	sort(a, a + n, [](pair<pair<int, int>, pair<int, pair<bool, bool>>> &b, pair<pair<int, int>, pair<int, pair<bool, bool>>> &c) {
			return b.second.first < c.second.first;
		});

	for (int i = 0; i < n; ++i) {
		cout << a[i].second.second.first << ' ';
	}
	cout << '\n';
	for (int i = 0; i < n; ++i) {
		cout << a[i].second.second.second << ' ';
	}
	cout << '\n';
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	#ifndef ONPC
		cout << "__________________________" << '\n';
		cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC <<
		"second(s)" << '\n';
	#endif
}
