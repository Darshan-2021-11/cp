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

	while (T--) {
		u32 a, b, l, lc, i, j, ans = 0;
		cin >> a >> b >> l;
		if (a == b) {
			++ans;
			while (l % a == 0) {
				l /= a;
				++ans;
			}
			cout << ans << '\n';
			continue;
		}
		for (i = 1; i * i < l; ++i) {
			if (l % i == 0) {
				lc = l / i;
				while (lc % a == 0) lc /= a;
				if (lc == 1 || lc % b == 0) ++ans;
				j = i;
				while (j % a == 0) j /= a;
				if (j == 1 || j % b == 0) ++ans;
			}
		}
		if (i * i == l) ++ans;
		else cout << ans << '\n';
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}
