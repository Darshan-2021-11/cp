#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

	u32 T = 1, n, nn, ans, r;
	cin >> T;
	vector<u32> a;
	vector<u32>::iterator it;

	while (T--) {
		ans = 0, r = 1;
		cin >> n;
		a.reserve(n);
		for(u32 i = 0; i < n; ++i) cin >> a.emplace_back();
		sort(a.begin(), a.end());
		it = unique(a.begin(), a.end());
		nn = it - a.begin();
		for (u32 i = 0; i < nn; ++i) {
			while (r < nn && a[r] - a[i] < n) ++r;
			ans = max(ans, r - i);
		}
		cout << ans << '\n';
		a.clear();
	}
	#ifndef ONLINE_JUDGE
		cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
	#endif
}

