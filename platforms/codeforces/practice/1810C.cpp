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

u32 T = 1, a[(u32)1e5], n;
u64 c, d, p, q;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), 
	cout.precision(15), cout.setf(ios::fixed);

	cin >> T;

	while (T--) [&]() {
		cin >> n >> c >> d;

		for (u32 i = 0; i < n; ++i) cin >> a[i];
		sort(a, a + n);
		p = n - !(q = a[0] != 1);
		//cout << "p = " << p << " q = " << q << '\t';

		u64 cost = p * c + q * d;
		if (q) {
			--p, q += a[0] - 2;
			cost = min(cost, p * c + q * d);
		}

		for (u32 i = 1; i < n; ++i) {
			if (a[i] == a[i - 1]) continue;
			--p, q += a[i] - a[i - 1] - 1;
			cost = min(cost, p * c + q * d);
		}
		cout << cost << '\n';
	}();
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

