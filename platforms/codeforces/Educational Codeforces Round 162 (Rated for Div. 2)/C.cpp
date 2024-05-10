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
		u64 l, r, diff, ones;
		u32 n, q;
		bool yes;
		cin >> n >> q;
		vector<u64> a; a.reserve(n);
		vector<u64> b(n + 1);
		vector<u64> c(n + 1);
		for (u32 i = 0; i < n; ++i) cin >> a.emplace_back();
		b[0] = 0, c[0] = 0;
		for (u32 i = 0; i < n; ++i) { b[i + 1] = b[i] + a[i]; }
		for (u32 i = 0; i < n; ++i) { c[i + 1] = c[i] + (a[i] == 1); }
		for (u32 i = 0; i < q; ++i) {
			cin >> l >> r;
			yes = true;
			if (r == l) yes = false;
			else {
				diff = r - l + 1;
				ones = c[r] - c[l - 1];
				if (b[r] - b[l - 1] < diff + ones) yes = false;
			}
			cout << (yes ? "YES\n": "NO\n");
		}

		cout << '\n';
	}
#ifndef ONLINE_JUDGE
	cout << '\n' << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "second(s)" << '\n';
#endif
}

