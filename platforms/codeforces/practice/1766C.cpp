#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

//mt19937 rnd(239);
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), 
	cout.precision(15), cout.setf(ios::fixed);

	u32 T = 1;
	cin >> T;
	string s[2];
	u32 n, stat, i;
	bool ans;

	while (T--) [&]() {
		cin >> n >> s[0] >> s[1];

		ans = true;
		stat = 2;  // Undetermined state

		for (i = 0; i < n && ans; i++) {
			if (s[0][i] == 'B' && s[1][i] == 'B') {
				if (stat != 2) stat ^= 1;  // Flip stat if not already 2
			} else if (s[0][i] == 'B' || s[1][i] == 'B') {
				if (stat != 2 && s[stat][i] != 'B') ans = false;
				if (stat == 2) stat = (s[1][i] == 'B');  // Set stat based on current character
			} else {
				ans = false;  // Both characters are not 'B'
			}
		}

		cout << (ans ? "YES\n" : "NO\n");
		s[0].clear(), s[1].clear();
	}();
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}
