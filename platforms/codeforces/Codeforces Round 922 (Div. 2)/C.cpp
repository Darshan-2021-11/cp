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
using ull = unsigned long long;
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
		ll a, b, r, x, u, t;
		bool changed = false;
		cin >> a >> b >> r;
		if (a < b) swap(a, b);
		u = a ^ b, x = 0;

		for (int i = 59; i > -1; --i) {
			t = 1ll << i;
			if (u & t) {
				if (!changed) {
					changed = true;
					continue;
				}
				if ((a & t) && (r >= t))
					x |= t, r -= t;
			}
		}
		cout << abs((a ^ x) - (b ^ x)) << '\n';
	}
	#ifndef ONLINE_JUDGE
		cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
	#endif
}
