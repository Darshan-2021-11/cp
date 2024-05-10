#ifdef ONPC
	#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using u32 = unsigned int;
using ll = long long;
using ld = long double;
// 1. Instead of less<int>, we can also do greater<T>, less_equal<T>,
// greater_equal<T> or any other custom function to compare
// 2. Two additional functions apart from all of that from the set is:
//	a) find_by_order(n), finds `n`th element (iterator)
//	b) order_of_key(n), finds elements smaller than `n` (value)
using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

//mt19937 rnd(239);
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int solve() {
	srand(time(0));
	int a[7];
	for (int i = 0; i < 7; ++i) {
		a[i] = rand() % 10 + 1;
	}
	map<int, vector<vector<int>>> score;
	for (int i = 0; i < 128; ++i) {
		vector<int> b, c;
		vector<vector<int>> d;
		int val = 0;
		for (int j = 0; j < 7; ++j) {
			if (i & (1 << j))
				b.push_back(a[j]);
			else
				c.push_back(a[j]);
		}
		for (int h = 1; h < (int)b.size(); ++h) {
			if (b[h - 1] < b[h]) ++val;
		}
		for (int h = 1; h < (int)c.size(); ++h) {
			if (c[h - 1] < c[h]) ++val;
		}
		d.emplace_back(b);
		d.emplace_back(c);
		score[val] = d;
	}
	for (auto i: score) {
		for (auto j: a) {
			cout << j << ' ';
		}
		cout << '\n' << i.first << '\n';
		for (auto j: i.second[0]) {
			cout << j << ' ';
		}
		cout << '\n';
		for (auto j: i.second[1]) {
			cout << j << ' ';
		}
		cout << '\n';
		break;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
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

