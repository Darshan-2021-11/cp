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

	u32 T = 1;
	cin >> T;

	u64 ans, d;
	u32 n, x, i, b;

	while (T--) {
		d = ans = 0;
		cin >> n >> x;
		u64 a[n];
		for (i = 0; i < n; ++i) { cin >> a[i]; }
		sort(a, a + n);
		i = 0;
		if (a[i] <= x)
			for (++i; i < n; ++i) {
				a[i] += a[i - 1];
				if (a[i] > x) break;
			};

		for (; i > 0; --i) {
			ans += (x - a[i - 1]) / i + 1;
		}
		cout << ans << '\n';
	}
	#ifndef ONLINE_JUDGE
		cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
	#endif
}

