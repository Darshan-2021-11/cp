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
	u32 a[200], n, m, x, y, xc, yc, i;

	while (T--) [&]() {
		cin >> n >> m;
		memset(a, 0, sizeof(u32) * n);
		while (m--) {
			cin >> x >> y;
			++a[x - 1], ++a[y - 1];
		}
		x = y = UINT32_MAX, xc = yc = 1;
		for (i = 0; i < n; ++i) {
			if (a[i] == 1) continue;
			if (x == UINT32_MAX) x = a[i];
			else if (x == a[i]) ++xc;
			else if (y == UINT32_MAX) y = a[i];
			else if (y == a[i]) ++yc;
		}
		if (y == UINT32_MAX)
			cout << x << ' ' << x - 1 << '\n';
		else if (xc == 1)
			cout << x <<  ' ' << y - 1 << '\n';
		else
			cout << y <<  ' ' << x - 1 << '\n';
	}();
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

