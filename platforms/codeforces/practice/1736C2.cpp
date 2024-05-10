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

	u32 a[(u32)2e5], n, t, q, i;
	u64 ans;

	ans = t = 0;
	cin >> n;
	vector<pair<u32, u32>> bp;
	for (i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] > t) ++t, ans += t;
		else t = a[i], ans += t, bp.emplace_back(i, t);
	}
	cin >> q;
	for (i = 0; i < q; ++i) {
		vector<pair<u32, u32>>::iterator it = lower_bound(bp.begin(), bp.end(), make_pair(i, 0), [](const pair<u32, u32> &x, const pair<u32, u32> &y) { return x.first < y.first; });
		cout << ans << '\n';
	}

#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}
