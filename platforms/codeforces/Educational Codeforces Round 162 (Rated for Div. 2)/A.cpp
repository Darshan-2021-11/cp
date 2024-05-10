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
		u32 n, count0 = 0, tmpcount0 = 0;
		bool found = false;
		cin >> n;
		vector<u32> a; a.reserve(n);
		for (u32 i = 0; i < n; ++i) {
			cin >> a.emplace_back();
			if (!found) { if (a.back() == 1) found = true; }
			else if (a.back() == 0) ++tmpcount0;
			else count0 += tmpcount0, tmpcount0 = 0;
		}
		if (!found) {
			cout << 0 << '\n';
		} else {
			cout << count0 << '\n';

		}
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

