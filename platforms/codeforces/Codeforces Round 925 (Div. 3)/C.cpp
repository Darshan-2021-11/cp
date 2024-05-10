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
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cout << std::fixed;
	cout.precision(15);

	u32 T = 1;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		int a[n], l = 0, r = n - 1;
		for (int i = 0; i < n; ++i) cin >> a[i];
		while (l < n && a[l] == a[l + 1]) ++l;
		while (r > 0 && a[r] == a[r - 1]) --r;
		if (n == 1) cout << 0 << '\n';
		else if (a[0] == a[n - 1]) cout << (l > r ? 0 : r - l - 1) << '\n';
		else if (l > n - 1 - r) cout << n - l - 1 << '\n';
		else if (r != n - 1) cout << r << '\n';
		else cout << n - 1 << '\n';
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

