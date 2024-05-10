#ifndef ONLINE_JUDGE
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
using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

//mt19937 rnd(239);
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int n, k, m, t, tc;
bool found, flag[26], alltrue;
int solve() {
	found = false;
	cin >> n >> k >> m;
	char a[m];
	int ac[26] { 0 }, cc[26] { 0 }, totc[26] { 0 };
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
		++ac[a[i] - 'a'];
	}
	for (t = 0; t < k; ++t) {
		if (ac[t] < n) {
			found = true;
			break;
		}
	}
	if (found) {
		cout << "NO\n";
		for (int i = 0; i < n; ++i) {
			cout << (char)('a' + t);
		}
		cout << '\n';
		return 0;
	}
	for (int i = 0; i < k; ++i) {
		flag[i] = false;
		ac[i] = min(n, ac[i]);
	}
	for (int i = 0; i < m; ++i) {
		alltrue = true;
		tc = a[i] - 'a';
		++totc[tc];
		if (!flag[tc])
			++cc[tc], flag[tc] = true;
		for (int j = 0; j < k; ++j) {
			if ((tc != j) && (ac[tc] - totc[tc] + cc[j]) < n - 1) {
				cout << "NO\n";
				for (int l = 0; l < n - (ac[tc] - totc[tc]); ++l) {
					cout << (char)('a' + j);
				}
				for (int l = 0; l < (ac[tc] - totc[tc]); ++l) {
					cout << a[i];
				}
				cout << '\n';
				return 0;
			}
			alltrue = alltrue && flag[j];
		}
		if (alltrue) {
			for (int j = 0; j < k; ++j) {
				flag[j] = false;
			}
		}
	}
	cout << "YES\n";
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1e9;
	cin >> T;
	#ifndef ONLINE_JUDGE
		cout << "__________________________" << '\n';
	#endif
	for (int i = 0; i < T; i++) {
		if (solve()) {
			break;
		}
		#ifndef ONLINE_JUDGE
			cout << "__________________________" << '\n';
		#endif
	}
	#ifndef ONLINE_JUDGE
		cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC <<
		"second(s)" << '\n';
	#endif
}

