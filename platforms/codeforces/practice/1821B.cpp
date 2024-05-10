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
	cin >> T;

	while (T--) {
		u32 n, fueq, lueq;
		cin >> n;
		fueq = n, lueq = 0;
		u32 a[n], b[n];
		for (u32 i = 0; i < n; ++i) cin >> a[i];
		for (u32 i = 0; i < n; ++i) {
			cin >> b[i];
			if (a[i] != b[i]) {
				if (fueq == n) {
					fueq = i;
				} else {
					lueq = i;
				}
			}
		}
		while (fueq && b[fueq - 1] <= b[fueq]) --fueq;
		while (lueq < n - 1 && b[lueq + 1] >= b[lueq]) ++lueq;
		cout << fueq + 1 << ' ' << lueq + 1 << '\n';
	}
	#ifndef ONLINE_JUDGE
		cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
	#endif
}

