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
	u32 n;
	bool hash;
	string a[2];

	while (T--) [&]() {
		hash = true;
		cin >> n;
		for (u32 i = 0; i < n; ++i) {
			a[0] += hash ? "##" : "..";
			a[1] += !hash ? "##" : "..";
			hash = !hash;
		}
		for (u32 i = 0; i < n; ++i) {
			if (i & 1) cout << a[1] << '\n' << a[1] << '\n';
			else cout << a[0] << '\n' << a[0] << '\n';
		}
		a[0].clear(), a[1].clear();

	}();
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

