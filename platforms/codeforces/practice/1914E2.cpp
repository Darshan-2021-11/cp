#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using u32 = unsigned int;
using u64 = unsigned long long;
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
		int n;
		cin >> n;
		ll ans = -(n & 1);
		vector<pair<int, int>> marbles(n);
		for (int i = 0; i < n; ++i) cin >> marbles[i].first;
		for (int i = 0; i < n; ++i) cin >> marbles[i].second;
		sort(marbles.begin(), marbles.end(), [](pair<int, int> a, pair<int, int> b) { return a.first + a.second > b.first + b.second; });
		for (int i = 0; i < n; ++i) i & 1 ? ans -= marbles[i].second : ans += marbles[i].first;

		cout << ans << '\n';
		
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

