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
		u64 total = 0;
		u32 n;
		cin >> n;
		u32 t, ones = 0, al = 0, bo = 0;
		for (u32 i = 0; i < n; ++i) {
			cin >> t;
			if (t == 1) ++ones;
			else total += t;
		}
		al = (ones + 1) >> 1;
		bo = ones >> 1;

		if (ones & 1) {
			if (total & 1)
				bo += n - ones;
			else
				al += n - ones;
		} else {
			if (total & 1)
				al += n - ones;
			else
				bo += n - ones;
		}
		if (al == bo) cout << "DRAW\n";
		else if (al > bo) cout << "ALICE\n";
		else cout << "BOB\n";
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

