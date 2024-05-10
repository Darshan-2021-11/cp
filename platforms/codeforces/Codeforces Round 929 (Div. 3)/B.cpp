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
		u32 n, t = 0;
		cin >> n;
		u64 sum = 0;
		bool onemod3 = false;
		for (u32 i = 0; i < n; ++i) {
			cin >> t;
			sum += t;
			if (t % 3 == 1) onemod3 = true;
		}
		if (sum % 3 == 0) cout << 0 << '\n';
		else if (sum % 3 == 1) cout << (onemod3 ? 1 : 2) << '\n';
		else if (sum % 3 == 2) cout << 1 << '\n';
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

