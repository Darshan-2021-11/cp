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

	u32 T = 1, acount, amin, ans;
	bool possible;
	cin >> T;

	string s;
	vector<u32> c;
	while (T--) {
		acount = ans = 0;
		cin >> s;
		c.push_back(1);
		for (u32 i = 1; i < s.size(); ++i) {
			if (s.at(i - 1) != s.at(i)) {
				if (s.at(i - 1) == 'A')
					acount += c.back();
				c.push_back(1);
			} else {
				++c.back();
			}
		}
		if (s.back() == 'A')
			acount += c.back();

		ans += acount;
		if (c.size() & 1) {
			if (c.size() == 1) {
				ans = 0;
			} else if (s.at(0) == 'A') {
				possible = false, amin = UINT32_MAX;
				for (u32 i = 0; i < c.size(); ++i) {
					if (i & 1) {
						if (c.at(i) > 1) {
							possible = true;
							break;
						}
					} else {
							amin = min(amin, c.at(i));
					}
				}
				if (!possible)
					ans -= amin;
			}
		}
		cout << ans << '\n';
		c.clear();
	}
	#ifndef ONLINE_JUDGE
		cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
	#endif
}

