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
	const u32 MOD = 1e9 + 7;
	cin >> T;

	while (T--) {
		ll x, p, t, ans;
		u32 q;
		cin >> x >> q;
		map<u32, u32> xfactors;
		t = x;
		// find all the prime factors
		while ((t & 1) == 0) { 
			++xfactors[2];
			t >>= 1; 
		}
		for (u32 i = 3; i * i <= t; i += 2) { 
			while (t % i == 0) {
				++xfactors[i];
				t = t / i;
			}
		} 

		for (u32 i = 0; i < q; ++i) {
			ans = 1;
			cin >> p;
			if (p != 1)
				for (auto j: xfactors) {
					if (j.second % p == 0) {
						ans <<= 1;
						ans %= MOD;
					}
				};
			cout << ans << '\n';
		}
	}
	#ifndef ONLINE_JUDGE
		cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
	#endif
}
