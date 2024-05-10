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
		u64 ans = 0;
		u32 n, t;
		cin >> n;
		vector<pair<u32, u32>> a;
		vector<u32> c;
		multiset<u32> b;
		a.reserve(n), c.reserve(n);
		for (u32 i = 0; i < n; ++i) { cin >> t; a.emplace_back(make_pair(t, 0)); }
		for (u32 i = 0; i < n; ++i) { cin >> t; b.insert(t); }
		for (u32 i = 0; i < n; ++i) cin >> c.emplace_back();
		sort(a.begin(), a.end());
		sort(c.rbegin(), c.rend());
		for (u32 i = n - 1; i < n; --i) {
			auto it = b.upper_bound(a[i].first);
			a[i].second = *it;
			b.erase(it);
		}
		sort(a.begin(), a.end(), [](pair<u32, u32> x, pair<u32, u32> y) { return x.second - x.first < y.second - y.first; });
		for (u32 i = 0; i < n; ++i) {
			ans += 1ll * c[i] * (a[i].second - a[i].first);
		}
		cout << ans << '\n';

	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

