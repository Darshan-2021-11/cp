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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(15);

	u32 T = 1;
	cin >> T;

	while (T--) {
		u32 n, k, t, odd = 1, even = 2;
		cin >> n >> k;
		t = k >> 1;
		if (k & 1) {
			while (odd <= n - (t << 1)) {
				cout << odd << ' ';
				odd += 2;
			}
			for (u32 i = 0; i < t; ++i) {
				cout << even << ' ' << odd << ' ';
				odd += 2, even += 2;
			}
			while (even <= n) {
				cout << even << ' ';
				even += 2;
			}
		} else {
			for (u32 i = 0; i < t; ++i) {
				cout << odd << ' ' << even << ' ';
				odd += 2, even += 2;
			}
			while (even <= n) {
				cout << even << ' ';
				even += 2;
			}
			while (odd <= n) {
				cout << odd << ' ';
				odd += 2;
			}
		}
		cout << '\n';
	}
	#ifndef ONLINE_JUDGE
		cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
	#endif
}

